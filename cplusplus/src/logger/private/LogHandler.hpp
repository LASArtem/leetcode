#pragma once

#include "LogPrefix.hpp"
#include "LogStream.hpp"
#include "STDDumpers.hpp"

#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <thread>
#include <vector>

namespace log {

class LogHandler {
public:
    ~LogHandler();
    static LogHandler& getInstance();

    void log(const eLogLevel& level, const std::string& prefix, const std::string& message);

    static void logMethod(const std::string& methodName);

    template<typename Arg, typename... Args>
    static void logMethod(const std::string& methodName, Arg&& arg, Args&&... args)
    {
        const std::unique_ptr<LogStream> logStream
            = std::make_unique<LogStream>("", eLogLevel::logInfo);
        *logStream << methodName << "(" << std::forward<Arg>(arg);
        (..., (*logStream << ", " << std::forward<Args>(args)));
        *logStream << ")";
    }

    static void logMethod(const LogPrefix& pref, const std::string& methodName);

    template<typename Arg, typename... Args>
    static void logMethod(
        const LogPrefix& pref, const std::string& methodName, Arg&& arg, Args&&... args)
    {
        try {
            const std::unique_ptr<LogStream> logStream
                = std::make_unique<LogStream>(pref.getPrefix(), eLogLevel::logInfo);

            *logStream << methodName << "(" << std::forward<Arg>(arg);
            (..., (*logStream << ", " << std::forward<Args>(args)));
            *logStream << ")";
        } catch (...) {
            // TODO handle exception
        }
    }

private:
    LogHandler();
};

} // namespace log