// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "ZigBee_Network.h"
#include "MBus_Network.h"
#include "NetworkFactory.hpp"

#include <iostream>

int main()
{
    std::cout << "Design Patterns\n";
    {
        NetworkBase base;

        auto comms = base.chooseNetwork("Z");

        comms->openConnection();
        comms->send("message");
        comms->receive();
        comms->closeConnection();

        comms = base.chooseNetwork("M");
        comms->openConnection();
        comms->send("message");
        comms->receive();
        comms->closeConnection();
    }
    {
        auto comms = make_network<ZigBee>();

        // Is a limitation of this method. See notes.
        // To make it working make class Zigbee members public
        comms.openConnection();
        comms.send("message");
        comms.receive();
        comms.closeConnection();
    }
  }
