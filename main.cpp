#include "NetworkInterface.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    NetworkInterface intf; // Connect
    intf.initSocket("93.184.216.34", 80);
    intf.sendRequest(
            "GET /index.html HTTP/1.1\r\n"
            "Host: example.com\r\n"
            "Connection: close\r\n\r\n");

    std::cout << intf.readResponse();

    std::string move = intf.getMove();
    intf.sendRequest(move);


    
    // If you're the first player
        // Server asks if you want to play PvP or AI
        
        // If PvP, wait for P2...
        // Else if AI...
    
    // Start game
    // Server assigns color

    // If white
        // Take turn
    
    // Wait for response...
    // Take turn

}
