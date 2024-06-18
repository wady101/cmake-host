// EventLogParser.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#include <memory>
#ifndef EVENTLOGPARSER_H
#define EVENTLOGPARSER_H

#include <string_view>

#include "Builder.h"

class EventLogParser {
public:
  EventLogParser() = default;
  void construct(std::string_view filename);
  void change_builder(std::unique_ptr<Builder> builder_) {
      this->builder = std::move(builder_);
  }


private:
  std::unique_ptr<Builder> builder;
};

#endif // EVENTLOGPARSER_H
