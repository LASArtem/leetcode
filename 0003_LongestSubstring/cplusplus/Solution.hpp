#pragma once

#include <string>

class Solution {
public:
    Solution();

    int lengthOfLongestSubstring(std::string s);
    std::string getLongestSubstring() const;

private:
    bool isUniqueChars(std::string s) const;

    std::string mLongestSubstring;
};