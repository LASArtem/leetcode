#pragma once

#include <string>

namespace log {
enum class eLogLevel : uint8_t {
    logOff = 0U,
    logFatal = 1U,
    logError = 2U,
    logWarn = 3U,
    logInfo = 4U,
    logDebug = 5U,
    logVerbose = 6U
};

enum class eCallType : uint8_t {
    staticCall,
    invoke,
    call,
    staticEvent,
    inlineEvent,
    event,
    request
};

std::string callTypeToString(const eCallType& type);
} // namespace log