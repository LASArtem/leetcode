#pragma once

#include "ISolution.hpp"

class SolutionDefault : public ISolution {
public:
    SolutionDefault();

    // ISolutions
    bool isReady() const override;
    void describeIssue() const override;
    void run() override;

    // Debuggable
    inline std::string buildPrefix() const override
    {
        return ISolution::buildPrefix() + "Default]";
    }
};