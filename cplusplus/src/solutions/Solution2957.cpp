#include "Solution2957.hpp"

#include <set>

Solution2957::Solution2957()
    : ISolution()
{
}

bool Solution2957::isReady() const
{
    return true;
}

void Solution2957::describeIssue() const
{
    logWarn() << "Remove Adjacent Almost-Equal Characters";
}

void Solution2957::run()
{
    std::string word{"zyxyxyz"};

    logVerbose() << "Input params:";
    logVerbose() << "    1) word: " << word;

    // task call
    const auto operationCounter = removeAlmostEqualCharacters(word);
    logWarn() << "operationCounter: " << operationCounter;
}

int Solution2957::removeAlmostEqualCharacters(std::string& word)
{
    const int wordLength = word.size();
    if (wordLength == 1) {
        return 0;
    }

    int operationCounter = 0;
    const int delta = 1; // show how close letter can not be
    for (int i = 1; i < wordLength; ++i) {
        logVerbose() << i << ": " << word[i - 1] << " - " << word[i] << " = "
                     << word[i - 1] - word[i];
        const int diff = word[i - 1] - word[i];
        if ((diff <= delta) && (diff >= -delta)) {
            word[i] = '0';
            ++operationCounter;
        }
    }

    return operationCounter;
}