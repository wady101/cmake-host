

#include "EventLog.h"
#include "DateTime.h"
#include "EventLogParser.h"

#include <iostream>
#include <fstream>

void EventLog::setLogFile(std::string_view filename_)
{
    auto& instance = get_instance();
    instance.filename = filename_;
}
EventLog& EventLog::get_instance() 
{
    static EventLog instance {};
    return instance;
}

void EventLog::write(std::string str) 
{
    static int ctr = 0;
    ctr++;
    towrite.append("Log entry: " + std::to_string(ctr) + "\n");
    towrite.append(DateTime::now());
    towrite.append(str);
    std::ofstream MyFile{filename, std::ios_base::app};
    MyFile << towrite  << "\n";
    MyFile.flush();
    towrite.clear();

}
