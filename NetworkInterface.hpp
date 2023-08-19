#include <asio.hpp>
#include <vector>

class NetworkInterface {
public:
    NetworkInterface();

    void connectToServer(std::string ip_address, unsigned short port_num);

private:
    //void readSomeData(asio::ip::tcp::socket& sock);

    //std::vector<char> m_buffer;

};