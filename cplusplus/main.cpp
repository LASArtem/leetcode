// Logger
#include <Logger.hpp>

// Solution
#include <ISolution.hpp>
#include <SolutionFactory.hpp>

int main(int argc, char** argv)
{
    if (argc == 2) {
        const uint32_t taskNumber = std::atoi(argv[1]);
        SolutionFactory factory{};
        const auto solution = factory.createSolution(taskNumber);

        if (solution->isReady()) {
            solution->describeIssue();
            solution->run();
        } else {
            log::logError() << "Task_" << taskNumber << " does not implemented";
        }
    } else {
        log::logError() << "Incorrect input params:";
        for (int i = 0; i < argc; ++i) {
            log::logError() << " param[" << i << "]: " << argv[i];
        }
    }

    return 0;
}
