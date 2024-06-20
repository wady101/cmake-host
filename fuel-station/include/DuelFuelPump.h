// DuelFuelPump.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef DUAL_PUMP_H
#define DUAL_PUMP_H

using GBP = double;
using litres = double;

class DuelFuelPump {
public:
  DuelFuelPump() = default;
  void buyFuel1(litres fuel);
  void buyFuel2(litres fuel);
  void updateFuelPrice(GBP price1, GBP price2) { fuel1Price = price1; fuel2Price = price2; }

private:
  GBP fuel1Price{1.0};
  GBP fuel2Price{1.0};
};

#endif
