//
// Created by timofey on 08.08.2020.
//

#include "date.h"

Date ParseDate(std::istream &is) {
  std::string line;
  is >> std::ws;
  getline(is, line, ' ');
  if (line.empty()) {
    return Date(10000, 0, 0);
  }
  std::istringstream iss(line);
  int year = 10000, month = 0, day = 0;
  char trash; // consume "-"
  iss >> year >> trash >> month >> trash >> day;
  return Date(year, month, day);
};

bool operator>(const Date &date1, const Date &date2) {
  if (date1.Year == date2.Year) {
    if (date1.Month == date2.Month) {
      return date1.Day > date2.Day;
    } else {
      return date1.Month > date2.Month;
    }
  } else {
    return date1.Year > date2.Year;
  }
}
bool operator<(const Date &date1, const Date &date2) {
  if (date1.Year == date2.Year) {
    if (date1.Month == date2.Month) {
      return date1.Day < date2.Day;
    } else {
      return date1.Month < date2.Month;
    }
  } else {
    return date1.Year < date2.Year;
  }
}
std::ostream &operator<<(std::ostream &os, const Date& date) {
  if (!(date.Year / 1000)) {
    if (!(date.Year / 100)) {
      if (!(date.Year / 10)) {
        os << "000" << date.Year;
      } else {
        os << "00" << date.Year;
      }
    } else {
      os << "0" << date.Year;
    }
  } else {
    os << date.Year;
  }
  os << "-";
  if (!(date.Month / 10)) {
    os << "0" << date.Month;
  } else {
    os << date.Month;
  }
  os << "-";
  if (!(date.Day / 10)) {
    os << "0" << date.Day;
  } else {
    os << date.Day;
  }
  return os;
}

bool operator==(const Date &date1, const Date &date2) {
  return !(date1 < date2) && !(date2 < date1);
}
bool operator!=(const Date &date1, const Date &date2) {
  return date1 < date2 || date1 > date2;
}

Date::Date(int year, int month, int day)
    : Year(year), Month(month), Day(day) {}
