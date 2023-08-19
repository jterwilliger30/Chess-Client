#include "NetworkInterface.hpp"
#include <iostream>

#include <chrono>
std::vector<char> m_buffer(20*1024);
NetworkInterface::NetworkInterface()
{
    //m_buffer.reserve(20 * 1024);
}

void NetworkInterface::connectToServer(std::string ip_address, unsigned short port_num)
{
    asio::error_code ec;

    asio::io_context context;
    asio::io_context::work idleWork(context);
    std::thread thread_context = std::thread([&]() {context.run(); });

    asio::ip::tcp::endpoint ep(asio::ip::make_address(ip_address, ec), port_num);

    asio::ip::tcp::socket sock(context);

    sock.connect(ep, ec);

    if (!ec)
    {
        std::cout << "Connected!" << std::endl;
    }
    else
    {
        std::cout << "Failed to connect to address" << ec.message() << std::endl;
    }

    if (sock.is_open())
    {
        

        std::string sRequest =
            "GET /index.html HTTP/1.1\r\n"
            "Host: example.com\r\n"
            "Connection: close\r\n\r\n";

        sock.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);

        size_t bytes = 0;
        while (bytes == 0)
        {
            bytes = sock.available();
        }

        sock.read_some(asio::buffer(m_buffer.data(), m_buffer.size()));
        for (auto c : m_buffer)
        {
            std::cout << c;
        }

        std::string move = "  ";
        while (!isalpha(move[0]) || !isdigit(move[1]))
        {
            std::cout << "\nYour move" << std::endl;
            std::getline(std::cin, move);
        }
        
        
    }

    

    
}


/* Async read... not desirable for our use case, since we want our calls to be blocking
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