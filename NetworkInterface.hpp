#include <asio.hpp>
#include <vector>

class NetworkInterface {
public:
    NetworkInterface();

    void initSocket(std::string ip_address, unsigned short port_num);
    void sendRequest(std::string sRequest);
    void waitForResponse();
    std::string readResponse();
    std::string getMove();

private:
    //void readSomeData(asio::ip::tcp::socket& sock);

    //std::vector<char> m_buffer;

    asio::error_code ec;
    asio::io_context context;

    //std::unique_ptr<asio::io_context::work> idleWork;
    //std::unique_ptr<std::thread> thread_context;

    std::unique_ptr<asio::ip::tcp::endpoint> ep;
    std::unique_ptr<asio::ip::tcp::socket> sock;

};