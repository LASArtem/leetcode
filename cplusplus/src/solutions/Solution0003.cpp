#include "Solution0003.hpp"

#include <algorithm>
#include <iostream>

Solution0003::Solution0003()
    : ISolution{}
    , mLongestSubstring{}
    , mTabCounter{0U}
{
}

bool Solution0003::isReady() const
{
    return true;
}

void Solution0003::describeIssue() const
{
    std::cout << "[Issue 0003] Longest Substring Without Repeating Characters" << std::endl;
}

void Solution0003::run()
{
    std::string checkingString{"ABCADEFG"};

    std::cout << "\nInput params:" << std::endl;
    std::cout << "\t1) string : " << checkingString << std::endl;

    const int maxLength = lengthOfLongestSubstring(checkingString);

    std::cout << "\nThe substring is: " << getLongestSubstring() << std::endl;
    std::cout << "The length is   : " << maxLength << std::endl;
}

int Solution0003::lengthOfLongestSubstring(const std::string& s)
{
    if (!s.empty()) {
        uint32_t counter = 0UL;
        size_t startPos = 0UL;
        do {
            ++counter;
            std::cout << "\nChar_" << counter << std::endl;
            mTabCounter = 0U;
            mUniqueSubstring.clear();
            saveUniqueString(s, startPos, s.size());
            if (mLongestSubstring.size() < mUniqueSubstring.size()) {
                std::cout << "mUniqueSubstring[" << mUniqueSubstring.size()
                          << "]: " << mUniqueSubstring << std::endl;
                mLongestSubstring = mUniqueSubstring;
            } else {
                std::cout << std::endl;
            }
            ++startPos;
        } while (s.size() > (startPos + mLongestSubstring.size()));
    }
    return mLongestSubstring.size();
}

std::string Solution0003::getLongestSubstring() const
{
    return mLongestSubstring;
}

void Solution0003::saveUniqueString(
    const std::string& s, const size_t startPos, const size_t finishPos)
{
    ++mTabCounter;
    for (uint8_t i = 0UL; i < mTabCounter; ++i) {
        std::cout << "\t";
    }
    std::cout << "getUniqueString: [" << startPos << ":" << finishPos << "]" << s;

    // if (s[startPos] == mUniqueSubstring[mUniqueSubstring.size() - 1UL] || startPos > finishPos) {
    if (startPos >= finishPos) {
        std::cout << std::endl;
    } else {
        char checkedChar = s[startPos];
        const auto repeatPos = s.find(checkedChar, startPos + 1);
        const auto newFinishPos
            = (repeatPos == std::string::npos) ? finishPos : std::min(repeatPos, finishPos);
        mUniqueSubstring.push_back(checkedChar);
        std::cout << "; checkedChar=" << checkedChar << "; repeatPos=" << repeatPos
                  << "; mUniqueSubstring=" << mUniqueSubstring << std::endl;
        saveUniqueString(s, startPos + 1UL, newFinishPos);
    }
}