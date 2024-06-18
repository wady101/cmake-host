// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "DateTime.h"
#include "EventLogParser.h"
#include "EventLog.h"
#include "HTMLBuilder.h"
#include "XMLBuilder.h"

#include <iostream>
#include <fstream>
#include <memory>

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

  EventLogParser elp{};
  std::unique_ptr<Builder> build = std::make_unique<HtmlBuilder>();
  elp.change_builder(std::move(build));
  elp.construct("log.txt");
  build = std::make_unique<XMLBuilder>();
  elp.change_builder(std::move(build));
  elp.construct("log.txt");
}
