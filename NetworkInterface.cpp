#include "NetworkInterface.hpp"
#include <iostream>

#include <chrono>


NetworkInterface::NetworkInterface() :
    ep(nullptr),
    sock(nullptr)
{
    //m_buffer.reserve(20 * 1024);
}

void NetworkInterface::initSocket(std::string ip_address, unsigned short port_num)
{
    //  Asynchronous tools
    //asio::io_context::work idleWork(context);
    //std::thread thread_context = std::thread([&]() {context.run(); });

    ep = std::make_unique<asio::ip::tcp::endpoint>(asio::ip::make_address(ip_address, ec), port_num);
    sock = std::make_unique<asio::ip::tcp::socket>(context);

    sock->connect(*ep, ec);

    if (!ec)
    {
        std::cout << "Connected!" << std::endl;
    }
    else
    {
        std::cout << "Failed to connect to address" << ec.message() << std::endl;
    }
}

void NetworkInterface::sendRequest(std::string sRequest)
{
    if (sock->is_open())
    {
        sock->write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);
    }
}

void NetworkInterface::waitForResponse()
{
    if (sock->is_open())
    {
        size_t bytes = 0;
        while (bytes == 0)
        {
            bytes = sock->available();
        }
    }
}

std::string NetworkInterface::readResponse()
{
    std::vector<char> m_buffer(1024 * 10);
    if (sock->is_open())
    {
        sock->read_some(asio::buffer(m_buffer.data(), m_buffer.size()));
    }

    std::string response(m_buffer.begin(), m_buffer.end());
    return response;
}

std::string NetworkInterface::getMove()
{
    std::string move = "  ";
    while (!isalpha(move[0]) || !isdigit(move[1]))
    {
        std::cout << "\nYour move" << std::endl;
        std::getline(std::cin, move);
    }

    return move;
}


/*  Async read... not desirable for our use case, since we want our calls to be blocking
void NetworkInterface::readSomeData(asio::ip::tcp::socket& sock)
{
    sock.async_read_some(asio::buffer(m_buffer.data(), m_buffer.size()),
    [&](std::error_code ec, size_t length)
    {
        if (!ec)
        {
            std::cout << "\n\nRead " << length << "bytes\n\n";

            for (int i=0; i < length; i++)
            {
                std::cout << m_buffer[i];
            }

            readSomeData(sock);
        }
    });

}
*/