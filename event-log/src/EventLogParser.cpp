// EventLogParser.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "EventLogParser.h"
#include "HTMLBuilder.h"
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <memory>

using namespace std;

void EventLogParser::construct(std::string_view filename) {
  // The code below opens the specified file and reads it in.
  // The code assumes the file is structured as follows:
  // - Each log entry consists of 3 lines:
  //   - The log entry number
  //   - The date
  //   - The text of the log entry
  //
  // You may need to change these lines if your log file
  // is structured differently.
  //
  // The code reads each line into a string object, which
  // can then be manipulated / used with a Builder class.
  //

  ifstream logfile{filename.data()};

  if (!logfile) {
    cerr << "can't open output file \"" << filename << "\"\n";
    return;
  }

  while (!logfile.eof()) {

    string entry{};
    string date{};
    string text{};

    getline(logfile, entry);
    if (logfile.eof()) {
      break;
    }

    getline(logfile, date);
    if (logfile.eof()) {
      break;
    }

    getline(logfile, text);
    if (logfile.eof()) {
      break;
    }

    if (builder == nullptr)
        return;
    std::string str = "";
    builder->header(str);
    builder->middle(str, entry, date, text);
    builder->footer(str);
    std::cout << str << std::endl;
    // ---------------------------------------------------
    // TO DO:
    // Use the associated Builder object to construct
    // its product.
    //
    // ---------------------------------------------------
  }
} // file closes automatically
