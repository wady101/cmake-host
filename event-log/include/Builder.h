#ifndef BUILDER_H
#define BUILDER_H

#include <string_view>

class Builder {
    public:
        Builder() = default;
        virtual ~Builder() = default;
        virtual void header(std::string& str) = 0;
        virtual void middle(std::string& str, std::string entry, std::string date, std::string text) = 0;
        virtual void footer(std::string& str) = 0;
};


#endif /* BUILDER_H */
