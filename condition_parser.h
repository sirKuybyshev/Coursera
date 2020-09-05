#pragma once

#include "node.h"

#include <iostream>
#include <memory>

std::shared_ptr<Node> ParseCondition(std::istream &is);

void TestParseCondition();
