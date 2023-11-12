#include <ISolution.hpp>
#include <SolutionFactory.hpp>

#include <cstdlib>
#include <iostream>
#include <memory>

int main(int argc, char** argv)
{
    if (argc == 2) {
        const uint32_t taskNumber = std::atoi(argv[1]);
        const SolutionFactory factory{};
        const auto solution = factory.createSolution(taskNumber);

        if (solution->isReady()) {
            solution->describeIssue();
            solution->run();
        } else {
            std::cerr << "[ERROR] Task_" << taskNumber << " does not implemented" << std::endl;
        }
    } else {
        std::cerr << "[ERROR] Incorrect input params:" << std::endl;
        for (int i = 0; i < argc; ++i) {
            std::cerr << "[ERROR] param[" << i << "]: " << argv[i] << std::endl;
        }
    }

    return 0;
}
