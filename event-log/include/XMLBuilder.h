#ifndef XMLBUILDER
#define XMLBUILDER

#include "Builder.h"

#include <string>

class XMLBuilder : public Builder {
    public:
    void header(std::string &str) override {
        str.append("<?xml version = 1.0> \n");
        str.append("<log>\n");
    }
    
    void middle(std::string& str, std::string entry, std::string date, std::string text) override {
        str.append("<entry>" + entry + "</entry>\n");
        str.append("<dateTime>" + date + "</dateTime>\n");
        str.append("<text>" + text + "</text>\n");
    }
    void footer(std::string& str) override {
        str.append("</log>\n");
    }
    
};


#endif /* XMLBUILDER */
