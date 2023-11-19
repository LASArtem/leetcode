/*0005 Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

Example 1:
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.

Example 2:
    Input: s = "cbbd"
    Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#pragma once

#include "ISolution.hpp"

#include <string>

class Solution0005 : public ISolution {
public:
    Solution0005();

    // ISolutions
    bool isReady() const override;
    void describeIssue() const override;
    void run() override;

    // Debuggable
    inline std::string buildPrefix() const override
    {
        return ISolution::buildPrefix() + "0005]";
    }

private:
    std::string longestPalindrome(const std::string& s);
};