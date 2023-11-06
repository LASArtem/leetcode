#pragma once

#include <string>

class Solution {
public:
    Solution();

    int lengthOfLongestSubstring(const std::string&);
    std::string getLongestSubstring() const;

private:
    void saveUniqueString(const std::string& s, const size_t startPos, const size_t finishPos);

    std::string mLongestSubstring;
    std::string mUniqueSubstring;
    uint8_t mTabCounter;
};