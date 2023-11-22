#pragma once

#include <Debuggable.hpp>

#include <memory>

class ISolution;

class SolutionFactory : public log::Debuggable,
                        public std::enable_shared_from_this<SolutionFactory> {
public:
    SolutionFactory();
    ~SolutionFactory() = default;

    // Debuggable
    inline std::string buildPrefix() const override
    {
        std::stringstream stream;
        stream << "[SF_" << this << "]";
        return stream.str();
    }

    std::shared_ptr<ISolution> createSolution(const uint32_t taskNumber);
};