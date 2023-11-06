#include "helper.hpp"

namespace helper {

std::string vectorToString(const std::vector<int>& v, size_t elNumber)
{
    const auto addedElements = (0 == elNumber) ? v.size() : std::min(elNumber, v.size());

    std::string result{"{"};
    if (!v.empty()) {
        result.append(std::to_string(v[0UL]));
        for (auto i = 1UL; i < addedElements; ++i) {
            result.append(", ");
            result.append(std::to_string(v[i]));
        }
    }
    result.append("}");

    return result;
}

std::string listToString(const std::list<int>& l, size_t elNumber)
{
    const auto addedElements = (0 == elNumber) ? l.size() : std::min(elNumber, l.size());

    std::string result{"{"};
    if (!l.empty()) {
        size_t counter = 0UL;
        for (const auto element : l) {
            if (counter != 0) {
                result.append(", ");
            }
            result.append(std::to_string(element));
            ++counter;
            if (counter == elNumber) {
                break;
            }
        }
    }
    result.append("}");

    return result;
}

} // namespace helper