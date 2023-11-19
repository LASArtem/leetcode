#include "LogEnums.hpp"

namespace log {
std::string callTypeToString(const eCallType& type)
{
    std::string result{};
    switch (type) {
    case eCallType::staticCall:
        result = "SC";
        break;
    case eCallType::invoke:
        result = "I";
        break;
    case eCallType::call:
        result = "C";
        break;
    case eCallType::staticEvent:
        result = "SE";
        break;
    case eCallType::inlineEvent:
        result = "IE";
        break;
    case eCallType::event:
        result = "E";
        break;
    case eCallType::request:
        result = "REQ";
        break;
    default:
        result = "UNKNOWN";
        break;
    }
    return result;
}
} // namespace log