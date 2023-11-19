#pragma once

#include <Debuggable.hpp>

class ISolution : public log::Debuggable {
public:
    virtual ~ISolution() = default;

    virtual bool isReady() const = 0;
    virtual void describeIssue() const = 0;
    virtual void run() = 0;

    // Debuggable
    inline std::string buildPrefix() const override
    {
        return "[Solution: ";
    }
};