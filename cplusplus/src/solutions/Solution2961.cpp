#include "Solution2961.hpp"

#include <list>

Solution2961::Solution2961()
    : ISolution()
{
}

bool Solution2961::isReady() const
{
    return true;
}

void Solution2961::describeIssue() const
{
    logWarn() << "Double Modular Exponentiation";
}

void Solution2961::run()
{
    std::vector<std::vector<int>> variables{{4, 4, 3, 2}};
    int target = 1;

    logVerbose() << "Input params:";
    logVerbose() << "    1) variables : " << variables;
    logVerbose() << "    2) target    : " << target;

    // task call
    const auto correctIndexes = getGoodIndices2(variables, target);
    logWarn() << "correctIndexes: " << correctIndexes;
}

std::vector<int> Solution2961::getGoodIndices(
    std::vector<std::vector<int>>& variables, const int target)
{
    std::list<int> correctIndexes;
    int index = 0;

    do {
        const auto& module_a = variables[index][0] % 10;
        const auto& m = variables[index][3];
        if (target >= m) {
            // ignore current index and go to the next one
        } else if (m == 1) {
            if (target == 0) {
                correctIndexes.push_back(index);
            }
        } else {
            const auto& c = variables[index][2];
            const auto usefullDegree_b = variables[index][1] % 4;
            const auto firstBracket = getFirstBracketValue(module_a, usefullDegree_b);
            if (target == powWithModule(firstBracket, c, m)) {
                correctIndexes.push_back(index);
            }
        }

        ++index;
    } while (index < variables.size());

    return std::vector<int>{correctIndexes.begin(), correctIndexes.end()};
}

int Solution2961::getFirstBracketValue(const int& module_a, const int& usefullDegree_b)
{
    switch (module_a) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        switch (usefullDegree_b) {
        case 0:
            return 6;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 8;
        }
    case 3:
        switch (usefullDegree_b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 9;
        case 3:
            return 7;
        }
    case 4:
        switch (usefullDegree_b) {
        case 0:
        case 2:
            return 6;
        case 1:
        case 3:
            return 4;
        }
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        switch (usefullDegree_b) {
        case 0:
            return 1;
        case 1:
            return 7;
        case 2:
            return 9;
        case 3:
            return 3;
        }
    case 8:
        switch (usefullDegree_b) {
        case 0:
            return 6;
        case 1:
            return 8;
        case 2:
            return 4;
        case 3:
            return 2;
        }
    case 9:
        switch (usefullDegree_b) {
        case 0:
        case 2:
            return 1;
        case 1:
        case 3:
            return 9;
        }
    }
    return 0;
}

int Solution2961::powWithModule(const int base, int degree, const int module)
{
    if (base == 0 || base == 1) {
        return base;
    }

    int result = 1;
    do {
        result *= base;
        result %= module;
    } while (--degree != 0);

    return result;
}

// recurcive solution:
std::vector<int> Solution2961::getGoodIndices2(std::vector<std::vector<int>>& variables, int target)
{
    std::list<int> correctIndexes;
    int index = 0;

    do {
        const auto& module_a = variables[index][0] % 10;
        const auto usefullDegree_b = variables[index][1] % 4 == 0 ? 4 : variables[index][1] % 4;
        const auto& c = variables[index][2];
        const auto& m = variables[index][3];

        const auto firstBracket = powerRecurcive(module_a, usefullDegree_b, 10);
        if (target == powerRecurcive(firstBracket, c, m)) {
            correctIndexes.push_back(index);
        }
    } while (++index < variables.size());

    return std::vector<int>{correctIndexes.begin(), correctIndexes.end()};
}

int Solution2961::powerRecurcive(const int a, const int b, const int m)
{
    if (b == 0) {
        return 1;
    }

    int tmp = powerRecurcive(a, b / 2, m);
    return tmp * tmp * (b & 1 ? a : 1) % m;
}