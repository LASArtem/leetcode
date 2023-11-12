#include "SolutionFactory.hpp"

// Solutions:
#include "Solution0002.hpp"
#include "Solution0003.hpp"
#include "Solution1535.hpp"
#include "SolutionDefault.hpp"

SolutionFactory::SolutionFactory()
{
}

std::shared_ptr<ISolution> SolutionFactory::createSolution(const uint32_t taskNumber) const
{
    std::shared_ptr<ISolution> solution{nullptr};
    switch (taskNumber) {
    case 0002:
        solution = std::make_shared<Solution0002>();
        break;
    case 0003:
        solution = std::make_shared<Solution0003>();
        break;
    case 1535:
        solution = std::make_shared<Solution1535>();
        break;
    default:
        solution = std::make_shared<SolutionDefault>();
        break;
    }

    return solution;
}