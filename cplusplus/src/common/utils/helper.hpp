#pragma once

#include <list>
#include <string>
#include <vector>

namespace common::utils::helper {

std::string vectorToString(const std::vector<int>& v, size_t elNumber = 0UL);
std::string listToString(const std::list<int>& l, size_t elNumber = 0UL);

} // namespace common::utils::helper