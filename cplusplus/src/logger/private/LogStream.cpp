#include "LogStream.hpp"

#include "LogHandler.hpp"

namespace log {
const eLogLevel LogStream::MAX_LOG_LEVEL = static_cast<eLogLevel>(CMAKE_MAX_LOG_LEVEL);
LogStream::LogStream(const std::string& prefix, const eLogLevel logLevel)
    : mPrefix(prefix)
    , mLevel(logLevel)
{
}

LogStream::LogStream(LogStream&& other) noexcept
    : mBaseStream(std::move(other.mBaseStream))
    , mPrefix(std::move(other.mPrefix))
    , mLevel(std::exchange(other.mLevel, log::eLogLevel::logError))
{
}

LogStream::~LogStream() noexcept
{
    if (mLevel <= MAX_LOG_LEVEL) {
        try {
            LogHandler::getInstance().log(mLevel, mPrefix, mBaseStream.str());
        } catch (...) {
        }
    }
}

LogStream& LogStream::operator=(LogStream&& other) noexcept
{
    mBaseStream.swap(other.mBaseStream);
    std::swap(mPrefix, other.mPrefix);
    std::swap(mLevel, other.mLevel);
    return *this;
}
} // namespace log