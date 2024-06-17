#ifndef EVENTLOG_H
#define EVENTLOG_H

#include <string_view>
#include <string>

class EventLog {
    public:
        static void setLogFile (std::string_view filename);
        static EventLog& get_instance();
        void write(std::string str);
        EventLog(const EventLog&) = delete;
        EventLog(EventLog&&) = delete;
        EventLog& operator=(const EventLog &) = delete;
        EventLog& operator=(EventLog &&) = delete;
    protected:
        EventLog() = default;
    private:
        std::string filename;
        std::string towrite = "";
};


#endif /* EVENTLOG_H */
