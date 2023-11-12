#pragma once

#include <memory>

class ISolution;

class SolutionFactory {
public:
    SolutionFactory();
    ~SolutionFactory() = default;

    std::shared_ptr<ISolution> createSolution(const uint32_t taskNumber) const;
};