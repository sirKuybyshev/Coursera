//
// Created by timofey on 08.08.2020.
//

#ifndef COURSERA_DATE_H
#define COURSERA_DATE_H

#include <iostream>
#include <sstream>

class Date {
  int Year, Month, Day;

public:
  Date(int year, int month, int day);
  Date() = default;

  friend bool operator<(Date date1, Date date2);
  friend bool operator>(Date date1, Date date2);
  friend std::ostream &operator<<(std::ostream &os, Date date);
  friend bool operator!=(Date date1, Date date2);
  friend bool operator==(Date date1, Date date2);
};

Date ParseDate(std::istream &is);

bool operator<(Date date1, Date date2);

bool operator==(Date date1, Date date2);

bool operator!=(Date date1, Date date2);

bool operator>(Date date1, Date date2);

std::ostream &operator<<(std::ostream &os, Date date);

#endif // COURSERA_DATE_H
