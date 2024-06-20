// Console.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Console.h"
#include "Observer.h"
#include "SingleFuelPump.h"
#include <iostream>

using namespace std;

void Console::updatePetrolPrice(GBP newPrice) {
  petrolPrice = newPrice;

  Observe::updateObserver();
  // -----------------------------------------------
  // TO DO:
  // Inform any observers that the price has changed.
  //
}

void Console::updateDieselPrice(GBP newPrice) {
  dieselPrice = newPrice;

  Observe::updateObserver();
  // -----------------------------------------------
  // TO DO:
  // Inform any observers that the price has changed.
  //
}

void Console::updateLPGPrice(GBP newPrice) {
  LPGPrice = newPrice;

  Observe::updateObserver();
  // -----------------------------------------------
  // TO DO:
  // Inform any observers that the price has changed.
  //
}

