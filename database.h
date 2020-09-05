//
// Created by timofey on 08.08.2020.
//

#ifndef COURSERA_DATABASE_H
#define COURSERA_DATABASE_H

#include "date.h"

#include <algorithm>
#include <exception>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

struct Note {
  Date date;
  mutable std::vector<std::string> events;
  mutable std::set<std::string> eventsTree;
  Note(Date date1, const std::string &event1)
      : date(date1), events(std::vector<std::string>(1, event1)){};
  Note(Date date1, std::vector<std::string> &events1)
      : date(date1), events(events1){};
};

bool operator<(const Note &left, const Note &right);

bool operator>(const Note &left, const Note &right);


class Database {
  std::set<Note> notes;

public:
  void Add(Date date, const std::string &event);
  void Print(std::ostream &out) const;
  int RemoveIf(const std::function<bool(Date date, std::string event)> &pred);
  std::vector<Note>
  FindIf(const std::function<bool(Date, std::string)> &pred) const;
  Note Last(Date date) const;
};

std::ostream &operator<<(std::ostream &os, const Note &note);

#endif // COURSERA_DATABASE_H
