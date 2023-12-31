/*0003. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
  Input: s = "abcabcbb"
  Output: 3
  Explanation: The answer is "abc", with the length of 3.
Example 2:
  Input: s = "bbbbb"
  Output: 1
  Explanation: The answer is "b", with the length of 1.
Example 3:
  Input: s = "pwwkew"
  Output: 3
  Explanation: The answer is "wke", with the length of 3.

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#pragma once

#include "ISolution.hpp"

#include <string>

class Solution0003 : public ISolution {
public:
    Solution0003();

    // ISolutions
    bool isReady() const override;
    void describeIssue() const override;
    void run() override;

    // Debuggable
    inline std::string buildPrefix() const override
    {
        return ISolution::buildPrefix() + "0003]";
    }

private:
    int lengthOfLongestSubstring(const std::string&);
};