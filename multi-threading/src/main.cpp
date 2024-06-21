// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "MessageQueue.h"
#include <iostream>
#include "Thread.hpp"
#include <thread>

using std::cout;

constexpr int count = 10;

int main() {
  MessageQueue<Message> queue{};
  UI ui{queue};
  Display display{queue};

  auto run_policy = [](Thread &runnable) {
    bool finished{};
    do {
      finished = runnable.run();
    } while (!finished);
  };

  std::thread t1{run_policy, std::ref(ui)}; // we need std::ref using run policy method. 
                                            // Other way is to run a forever loop in *.run() func implementatation
                                            // and kill thread eof main
  std::thread t2{run_policy, std::ref(display)};

  t1.join();
  t2.join();
}
