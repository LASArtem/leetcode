#pragma once

#include "LogEnums.hpp"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

namespace log {
class LogStream {
public:
    LogStream(const std::string& prefix, const eLogLevel logLevel);
    LogStream(LogStream&& other) noexcept;
    LogStream(const LogStream&) = delete;
    ~LogStream() noexcept;

    LogStream& operator=(const LogStream&) = delete;
    LogStream& operator=(LogStream&& other) noexcept;

    template<typename ValueT>
    std::ostream& operator<<(ValueT const& val)
    {
        if (mLevel <= MAX_LOG_LEVEL) {
            mBaseStream << &std::boolalpha << val;
        }
        return mBaseStream;
    }

private:
    static const eLogLevel MAX_LOG_LEVEL;
    std::ostringstream mBaseStream;
    std::string mPrefix;
    eLogLevel mLevel;
};

template<typename ValueT>
std::unique_ptr<LogStream> operator<<(std::unique_ptr<LogStream> stream, const ValueT& val)
{
    if (stream) {
        *stream << val;
    }
    return stream;
}
} // namespace log