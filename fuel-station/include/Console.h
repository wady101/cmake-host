// Console.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#include "DuelFuelPump.h"
#include <vector>
#include "Observer.h"
#ifndef CONSOLE_H
#define CONSOLE_H

using GBP = double;

class Console : public Observe {
public:
  Console(GBP a, GBP b, GBP c) : petrolPrice(a), dieselPrice(b), LPGPrice(c) {};
  void updatePetrolPrice(GBP newPrice);
  void updateDieselPrice(GBP newPrice);
  void updateLPGPrice(GBP newPrice);
  GBP getPetrolPrice() {return petrolPrice;} 

private:
  GBP petrolPrice{};
  GBP dieselPrice{};
  GBP LPGPrice{};
};

#endif
