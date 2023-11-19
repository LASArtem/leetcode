#include "LogPrefix.hpp"

namespace log {
LogPrefix::LogPrefix(const std::string& prefix)
    : mPrefix(prefix)
{
}

std::ostream& operator<<(std::ostream& os, const LogPrefix& prefix)
{
    return os << prefix.getPrefix();
}

} // namespace log
