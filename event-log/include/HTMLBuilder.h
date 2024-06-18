#ifndef HTMLBUILDER_H
#define HTMLBUILDER_H

#include "Builder.h"

#include <string>

class HtmlBuilder : public Builder {
    public:
    void header(std::string &str) override {
        str.append("<!DOCTYPE html>\n");
        str.append("<html>\n");
    }
    
    void middle(std::string& str, std::string entry, std::string date, std::string text) override {
        str.append("<h1>" + entry + "</h1>\n");
        str.append("<h2>" + date + "</h2>\n");
        str.append("<p>" + text + "</p>\n");
    }
    void footer(std::string& str) override {
        str.append("</html>\n");
    }
    
};


#endif /* HTMLBUILDER_H */
