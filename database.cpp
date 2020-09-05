//
// Created by timofey on 08.08.2020.
//

#include "database.h"

using namespace std;

void Database::Add(Date date, const string &event) {
  Note note = Note(date, event);
  auto finded = notes.lower_bound(note);
  if (finded == notes.end() || finded->date != date) {
    auto inserted = notes.insert(Note(date, event));
    inserted.first->eventsTree.insert(event);
  } else {
    if (finded->eventsTree.upper_bound(event) ==
        finded->eventsTree.lower_bound(event)) {
      finded->events.push_back(event);
      finded->eventsTree.insert(event);
    }
  }
}

void Database::Print(ostream &out) const {
  for (const auto &note : notes) {
    out << note << endl;
  }
}

int Database::RemoveIf(const function<bool(Date, string)> &pred) {
  int count = 0;
  for (auto note = notes.begin(); note != notes.end(); note++) {
    auto thisDate = note->date;
    auto firstGood = stable_partition(note->events.begin(), note->events.end(),
                                     [thisDate, pred](const string &event) {
                                       return pred(thisDate, event);
                                     });
    for (auto item = note->events.begin(); item != firstGood; item++) {
      note->eventsTree.erase(*item);
      count++;
    }
    note->events.erase(note->events.begin(), firstGood);
  }
  auto item = notes.begin();
  while (item != notes.end()) {
    if(item->events.empty()) {
      item = notes.erase(item);
    } else {
      item++;
    }
  }
  return count;
}

Note Database::Last(Date date) const {
  auto last = upper_bound(notes.begin(), notes.end(), Note(date, ""));
  if (last == notes.begin()) {
    throw(invalid_argument(""));
  }
  last--;
  return Note(last->date, (last->events.back()));
}

std::vector<Note>
Database::FindIf(const function<bool(Date, string)> &pred) const {
  vector<Note> goods;
  for (const auto &note : notes) {
    for (const auto &event : note.events) {
      if (pred(note.date, event)) {
        goods.emplace_back(note.date, event);
      }
    }
  }
  return goods;
}

std::ostream &operator<<(ostream &os, const Note &note) {
  auto end = note.events.back();
  for (const auto &event : note.events) {
    if (event == end) {
      os << note.date << " " << event;
      return os;
    }
    os << note.date << " " << event << endl;
  }
  return os;
}

bool operator<(const Note &left, const Note &right) {
  return left.date < right.date;
}
bool operator>(const Note &left, const Note &right) {
  return left.date > right.date;
}
