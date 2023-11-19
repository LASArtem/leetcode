#pragma once

#include "private/LogEnums.hpp"
#include "private/LogHandler.hpp"

namespace log {
void logMethod(const std::string& methodName)
{
    LogHandler::logMethod(methodName);
}

inline std::unique_ptr<::log::LogStream> logVerbose()
{
    return std::move(std::make_unique<::log::LogStream>("", ::log::eLogLevel::logVerbose));
}

inline std::unique_ptr<::log::LogStream> logDebug()
{
    return std::move(std::make_unique<::log::LogStream>("", ::log::eLogLevel::logDebug));
}

inline std::unique_ptr<::log::LogStream> logInfo()
{
    return std::move(std::make_unique<::log::LogStream>("", ::log::eLogLevel::logInfo));
}

inline std::unique_ptr<::log::LogStream> logWarn()
{
    return std::move(std::make_unique<::log::LogStream>("", ::log::eLogLevel::logWarn));
}

inline std::unique_ptr<::log::LogStream> logError()
{
    return std::move(std::make_unique<::log::LogStream>("", ::log::eLogLevel::logError));
}

template<typename Arg, typename... Args>
void logMethod(const std::string& methodName, Arg&& arg, Args&&... args)
{
    LogHandler::logMethod(methodName, arg, std::forward<Args&&>(args)...);
}

} // namespace log