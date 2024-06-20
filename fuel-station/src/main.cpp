// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Console.h"
#include "DuelFuelPump.h"
#include "SingleFuelPump.h"

int main()
{
    Console console(1,1,1);
    SingleFuelPump petrol(&console);
    DuelFuelPump petrolDiesel{};

  petrol.buyFuel1(47.2);
  petrolDiesel.buyFuel1(32.5);
  petrolDiesel.buyFuel2(24.1);
}
