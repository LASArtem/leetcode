/*0007. Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1],
then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
    Input: x = 123
    Output: 321
Example 2:
    Input: x = -123
    Output: -321
Example 3:
    Input: x = 120
    Output: 21

Constraints:
-2^31 <= x <= 2^31 - 1
*/

#pragma once

#include "ISolution.hpp"

class Solution0007 : public ISolution {
public:
    Solution0007();

    // ISolutions
    bool isReady() const override;
    void describeIssue() const override;
    void run() override;

    // Debuggable
    inline std::string buildPrefix() const override
    {
        return ISolution::buildPrefix() + "0007]";
    }

private:
    int reverse(int64_t x);
};