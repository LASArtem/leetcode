#include "Solution0006.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

Solution0006::Solution0006()
    : ISolution{}
{
}

bool Solution0006::isReady() const
{
    return true;
}

void Solution0006::describeIssue() const
{
    logWarn() << "Zigzag Conversion";
}

void Solution0006::run()
{
    const std::string checkingString{"PAYPALISHIRING"};
    const int numRows = 4;

    logDebug() << "Input params:";
    logDebug() << "  1) string : " << checkingString;
    logDebug() << "  2) numRows: " << numRows;

    const auto zigzag = convert(checkingString, numRows);
    logDebug() << "The Zigzag Conversion is: " << zigzag;
    logDebug() << "The Zigzag is equal     : " << (zigzag.compare("PINALSIGYAHRPI") == 0);
}

std::string Solution0006::convert(const std::string& s, const int numRows)
{
    if (numRows == 1) {
        return s;
    }

    const int sSize = s.size();
    std::string zigzagString;
    for (int i = 0; i < numRows; ++i) {
        int currentCharPosition = i;

        if (i == 0 || i == (numRows - 1)) {
            const int charDelta = 2 * (numRows - 1);
            while (currentCharPosition < sSize) {
                zigzagString.push_back(s[currentCharPosition]);
                currentCharPosition += charDelta;
            }
        } else {
            const int firstCharDelta = 2 * (numRows - 1 - i);
            const int secondCharDelta = 2 * i;
            while (currentCharPosition < sSize) {
                zigzagString.push_back(s[currentCharPosition]);
                currentCharPosition += firstCharDelta;
                if (currentCharPosition < sSize) {
                    zigzagString.push_back(s[currentCharPosition]);
                    currentCharPosition += secondCharDelta;
                }
            }
        }
    }

    return zigzagString;
}