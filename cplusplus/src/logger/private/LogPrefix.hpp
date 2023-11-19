#pragma once

#include <ostream>
#include <string>

namespace log {

class LogPrefix {
public:
    LogPrefix(const std::string& prefix);

    inline const std::string& getPrefix() const
    {
        return mPrefix;
    }

private:
    std::string mPrefix;
};

std::ostream& operator<<(std::ostream& os, const LogPrefix& prefix);

} // namespace log