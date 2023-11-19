#include "Solution0003.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

Solution0003::Solution0003()
    : ISolution{}
{
}

bool Solution0003::isReady() const
{
    return true;
}

void Solution0003::describeIssue() const
{
    logWarn() << "Longest Substring Without Repeating Characters";
}

void Solution0003::run()
{
    std::string checkingString{"abcabcdab"};

    logDebug() << "Input params:";
    logDebug() << "    1) string : " << checkingString;

    const int maxLength = lengthOfLongestSubstring(checkingString);
    logDebug() << "The length is : " << maxLength;
}

int Solution0003::lengthOfLongestSubstring(const std::string& s)
{
    int longestSubstringSize = 0;
    if (!s.empty()) {
        std::vector<int> letterIndexes(255, -1);

        const size_t length = s.size();
        int i = 0;
        int startIndexOfSubsctring = 0;

        do {
            const auto letter = s[i];
            if (letterIndexes[letter] >= startIndexOfSubsctring) {
                startIndexOfSubsctring = letterIndexes[letter] + 1;
            }
            letterIndexes[letter] = i;

            longestSubstringSize = std::max(longestSubstringSize, i - startIndexOfSubsctring + 1);
            ++i;
        } while (i < length);
    }
    return longestSubstringSize;
}