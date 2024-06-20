// SingleFuelPump.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef SINGLE_PUMP_H
#define SINGLE_PUMP_H
#include "Console.h"

#include "Observer.h"

using GBP = double;
using litres = double;

class SingleFuelPump : public I_Observer {
public:
  SingleFuelPump(Console* console_) : console(console_) {Observe obs;};
  void buyFuel1(litres fuel);
  void updateFuelPrice(GBP fuel) {fuel1Price = fuel;}

protected:
  void update() override {fuel1Price = console->getPetrolPrice();};
private:
  GBP fuel1Price{1.0};
  Console *console;
};

#endif // SINGLE_PUMP_H
