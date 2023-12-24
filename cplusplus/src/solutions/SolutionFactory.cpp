#include "SolutionFactory.hpp"

// Solutions:
#include "Solution0002.hpp"
#include "Solution0003.hpp"
#include "Solution0005.hpp"
#include "Solution0006.hpp"
#include "Solution0007.hpp"
#include "Solution0008.hpp"
#include "Solution0149.hpp"
#include "Solution1535.hpp"
#include "Solution2956.hpp"
#include "Solution2961.hpp"
#include "SolutionDefault.hpp"

SolutionFactory::SolutionFactory()
{
}

std::shared_ptr<ISolution> SolutionFactory::createSolution(const uint32_t taskNumber)
{
    std::shared_ptr<ISolution> solution{nullptr};
    switch (taskNumber) {
    case 2:
        solution = std::make_shared<Solution0002>();
        break;
    case 3:
        solution = std::make_shared<Solution0003>();
        break;
    case 5:
        solution = std::make_shared<Solution0005>();
        break;
    case 6:
        solution = std::make_shared<Solution0006>();
        break;
    case 7:
        solution = std::make_shared<Solution0007>();
        break;
    case 8:
        solution = std::make_shared<Solution0008>();
        break;
    case 149:
        solution = std::make_shared<Solution0149>();
        break;
    case 1535:
        solution = std::make_shared<Solution1535>();
        break;
    case 2956:
        solution = std::make_shared<Solution2956>();
        break;
    case 2961:
        solution = std::make_shared<Solution2961>();
        break;
    default:
        solution = std::make_shared<SolutionDefault>();
        break;
    }

    solution->link(shared_from_this());
    return solution;
}