#include "Solution.hpp"

#include <algorithm>
#include <iostream>

Solution::Solution()
    : mLongestSubstring{}
{
}

int Solution::lengthOfLongestSubstring(std::string s)
{
    uint32_t counter = 0UL;
    do {
        ++counter;
        char testedChar = s.front();
        const auto repeatPos = s.find(testedChar, 1);
        const std::string substring = s.substr(0, repeatPos);
        if (mLongestSubstring.size() < substring.size()) {
            std::cout << "\nChar_" << counter << ":" << std::endl;
            std::cout << "Char:" << testedChar << "; substring: " << substring << std::endl;

            const bool isUnique = isUniqueChars(substring);

            if (isUnique) {
                std::cout << "\"" << substring
                          << "\" does not contains repeated characters. It was saved !!!"
                          << std::endl;
                mLongestSubstring = substring;
            }
        }
        s = s.substr(1);
    } while (s.size() > mLongestSubstring.size());

    return mLongestSubstring.size();
}

std::string Solution::getLongestSubstring() const
{
    return mLongestSubstring;
}

bool Solution::isUniqueChars(std::string s) const
{
    do {
        const char checkedChar = s.front();
        s = s.substr(1);
        if (std::string::npos != s.find(checkedChar)) {
            std::cout << "\tisUniqueChars: " << checkedChar << " is FOUND second time in \"" << s
                      << "\"" << std::endl;
            break;
        }
    } while (!s.empty());

    return s.empty();
}