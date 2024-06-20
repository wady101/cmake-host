// Timer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef TIMER_H
#define TIMER_H
#include "I_Command.h"
#include "Hardware.h"

#include <chrono>

class Timer : public I_Command, public Motor, public SevenSeg {
public:
  Timer(std::chrono::milliseconds period);
  void start(I_Command &cmd);

private:
  void timeout();
  std::chrono::milliseconds tick{};
};

#endif
