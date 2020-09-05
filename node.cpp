//
// Created by timofey on 08.08.2020.
//

#include "node.h"

#include <utility>

using namespace std;

bool EmptyNode::Evaluate(const Date &date, const string &event) { return true; }

DateComparisonNode::DateComparisonNode(Comparison comparison, Date date1)
    : cmp(comparison), date(date1) {}

bool DateComparisonNode::Evaluate(const Date &date1, const string &event) {
  switch (cmp) {
  case (Comparison::Equal):
    return date1 == date;
  case (Comparison::NotEqual):
    return date1 != date;
  case (Comparison::GreaterOrEqual):
    return (date < date1 || date1 == date);
  case (Comparison::Greater):
    return date < date1;
  case (Comparison::Less):
    return date > date1;
  case (Comparison::LessOrEqual):
    return (date > date1 || date1 == date);
  default:
    throw invalid_argument("Expected comparison");
  }
}
bool EventComparisonNode::Evaluate(const Date &date, const string &event1) {
  switch (cmp) {
  case (Comparison::Equal):
    return event1 == event;
  case (Comparison::NotEqual):
    return event1 != event;
  case (Comparison::GreaterOrEqual):
    return (event < event1 || event1 == event);
  case (Comparison::Greater):
    return (event < event1);
  case (Comparison::Less):
    return event > event1;
  case (Comparison::LessOrEqual):
    return event > event1 || event1 == event;
  default:
    throw invalid_argument("Unexpected comparison");
  }
}
EventComparisonNode::EventComparisonNode(Comparison comparison, string item)
    : cmp(comparison), event(std::move(item)) {}

LogicalOperationNode::LogicalOperationNode(LogicalOperation operation,
                                           shared_ptr<Node> left1,
                                           shared_ptr<Node> right1)
    : op(operation), left(std::move(left1)), right(std::move(right1)) {}
bool LogicalOperationNode::Evaluate(const Date &date, const string &event) {
  if (op == LogicalOperation::And) {
    return (left->Evaluate(date, event) && right->Evaluate(date, event));
  } else {
    return (left->Evaluate(date, event) || right->Evaluate(date, event));
  }
}
