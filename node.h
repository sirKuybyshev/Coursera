//
// Created by timofey on 08.08.2020.
//

#ifndef COURSERA_NODE_H
#define COURSERA_NODE_H

#include "date.h"

#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <string>

enum Comparison { Less, LessOrEqual, Greater, GreaterOrEqual, Equal, NotEqual };

enum LogicalOperation { And, Or };

class Node {
public:
  Node() = default;
  virtual bool Evaluate(const Date &date, const std::string &event) = 0;
};

class EmptyNode : public Node {
  bool Evaluate(const Date &date, const std::string &event) override;
};

class DateComparisonNode : public Node {
  Comparison cmp;
  Date date;

public:
  DateComparisonNode(Comparison, Date);
  bool Evaluate(const Date &date1, const std::string &event) override;
};

class EventComparisonNode : public Node {
  Comparison cmp;
  std::string event;

public:
  EventComparisonNode(Comparison, std::string);
  bool Evaluate(const Date &date1, const std::string &event1) override;
};

class LogicalOperationNode : public Node {
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
  LogicalOperation op;

public:
  LogicalOperationNode(LogicalOperation operation, std::shared_ptr<Node> left1,
                       std::shared_ptr<Node> right1);
  bool Evaluate(const Date &date, const std::string &event) override;
};

#endif // COURSERA_NODE_H
