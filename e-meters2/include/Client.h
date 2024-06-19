#ifndef CLIENT_H
#define CLIENT_H


#include "I_Meter.h"
#include <initializer_list>
class Client {
    private:
        std::initializer_list<I_Meter *> devices;
    public:
    Client(std::initializer_list<I_Meter *> list_) : devices(list_) {};
    void read() {
        for (auto device : devices)
            device->getReading();
    }
};

#endif /* CLIENT_H */
