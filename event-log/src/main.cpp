// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "DateTime.h"
#include "EventLogParser.h"
#include "EventLog.h"

#include <iostream>
#include <fstream>

using std::cout;

int main() {
  cout << "Design Patterns\n";

  cout << DateTime::now() << '\n';

  {
    std::string filename{"log.txt"}; // Can be opened by Notepad
    auto& obj = EventLog::get_instance();
    obj.setLogFile(filename);

    // Stream to the file object
    obj.write("MEOW");
    obj.write("MEOW2");

  } // file closed

  // EventLogParser elp{};
  // elp.construct("log.txt");
}
