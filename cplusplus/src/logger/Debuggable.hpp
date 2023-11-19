#pragma once

#include "private/LogHandler.hpp"
#include "private/LogPrefix.hpp"

#include <memory>
#include <string>

namespace log {
class Debuggable {
public:
    Debuggable() = default;

    virtual ~Debuggable() = default;

    virtual inline std::string buildPrefix() const = 0;

    inline void link(const std::weak_ptr<Debuggable>& parent)
    {
        mParent = parent;
    }

    inline std::unique_ptr<::log::LogStream> logVerbose() const
    {
        return std::move(
            std::make_unique<::log::LogStream>(getPrefix(), ::log::eLogLevel::logVerbose));
    }

    inline std::unique_ptr<::log::LogStream> logDebug() const
    {
        return std::move(
            std::make_unique<::log::LogStream>(getPrefix(), ::log::eLogLevel::logDebug));
    }

    inline std::unique_ptr<::log::LogStream> logInfo() const
    {
        return std::move(
            std::make_unique<::log::LogStream>(getPrefix(), ::log::eLogLevel::logInfo));
    }

    inline std::unique_ptr<::log::LogStream> logWarn() const
    {
        return std::move(
            std::make_unique<::log::LogStream>(getPrefix(), ::log::eLogLevel::logWarn));
    }

    inline std::unique_ptr<::log::LogStream> logError() const
    {
        return std::move(
            std::make_unique<::log::LogStream>(getPrefix(), ::log::eLogLevel::logError));
    }

    template<typename... Args>
    void logMethod(const std::string& methodName, Args&&... args) const
    {
        ::log::LogHandler::logMethod(
            ::log::LogPrefix(getPrefix()), methodName, std::forward<Args&&>(args)...);
    }

private:
    inline std::string getPrefix() const
    {
        std::string ret{""};
        if (auto shared = mParent.lock()) {
            ret = shared->getPrefix() + buildPrefix() + ": ";
        } else {
            ret = buildPrefix() + ": ";
        }
        return ret;
    }

    std::weak_ptr<Debuggable> mParent;
};

} // namespace log
