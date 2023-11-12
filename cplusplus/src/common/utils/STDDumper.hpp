#pragma once

#include <list>
#include <sstream>
#include <string>
#include <vector>

namespace common::utils::stddumper {

template<typename _Tp, uint32_t countToOutput = 0U>
struct log_vector {
    explicit log_vector(const std::vector<_Tp>& value)
        : mValue(value)
        , mCountToOutput(countToOutput)
    {
    }

    const std::vector<_Tp>& mValue;
    const uint32_t mCountToOutput;
};

template<typename _Tp, uint32_t countToOutput = 0U>
std::ostream& operator<<(std::ostream& out, const std::vector<_Tp>& _vector)
{
    return out << log_vector<_Tp, countToOutput>(_vector);
}

template<typename _Tp, uint32_t countToOutput = 0U>
std::ostream& operator<<(std::ostream& out, const log_vector<_Tp, countToOutput>& _vector)
{
    out << "{";

    uint32_t counter = 0U;
    for (auto it = _vector.mValue.begin(); it != _vector.mValue.end(); ++it) {
        if ((countToOutput > 0U) && (countToOutput <= counter)) {
            break;
        }
        ++counter;

        if (it != _vector.mValue.begin()) {
            out << ", ";
        }

        out << *it;
    }

    out << "}";

    return out;
}

std::string vectorToString(const std::vector<int>& v, size_t elNumber = 0UL);
std::string listToString(const std::list<int>& l, size_t elNumber = 0UL);

} // namespace common::utils::stddumper