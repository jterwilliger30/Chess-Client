#include "NetworkInterface.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    NetworkInterface intf; // Connect
    //intf.initSocket("52.8.155.121", 12819);
    intf.initSocket("127.0.0.1", 12819);
    intf.sendRequest("I want to play,a");
    
    while (true)
    {
        intf.waitForResponse();
        std::cout << intf.readResponse() << std::endl;
        std::string move = intf.getMove();
        intf.sendRequest(move);
    }
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
