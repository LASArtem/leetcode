#include "SolutionDefault.hpp"

#include <iostream>

SolutionDefault::SolutionDefault()
    : ISolution()
{
}

// ISolutionDefaults
bool SolutionDefault::isReady() const
{
    return false;
}

void SolutionDefault::describeIssue() const
{
    std::cout << "Issue: unkown issue" << std::endl;
}

void SolutionDefault::run()
{
    // do nothing
}