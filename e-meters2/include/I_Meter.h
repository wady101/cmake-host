// I_Meter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#include "I_Network.h"
#include <iostream>
#ifndef I_METER_H
#define I_METER_H

// -------------------------------------------
// INTERFACE FOR METER CLASSES
//
class I_Meter {
public:
  virtual void getReading() = 0;
  virtual ~I_Meter() = default;
};

class Meter : public I_Meter {
    protected:
        I_Network *network;
    public:
        Meter(I_Network& network_) {network = &network_; network->openConnection();}
        ~Meter() {network->closeConnection();}
        virtual void getReading() override {
            std::cout << network->receive();
        }
};
class GasMeter : public Meter {
    public:
        GasMeter(I_Network& network_) : Meter(network_) {}
    void getReading() override {
        std::cout << "Demand Gas reading";
        network->receive();
    }
};

class ElectricityMeter : public Meter {
    public:
        ElectricityMeter(I_Network& network_) : Meter(network_) {}
    void getReading() override {
        std::cout << "Demand Electricity reading";
        network->receive();
    }
};
class WaterMeter : public Meter {
    public:
        WaterMeter(I_Network& network_) : Meter(network_) {}
    void getReading() override {
        std::cout << "Demand Water reading";
        network->receive();
    }
};

#endif // I_METER_H
