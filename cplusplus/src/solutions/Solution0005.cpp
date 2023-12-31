#include "Solution0005.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

Solution0005::Solution0005()
    : ISolution{}
{
}

bool Solution0005::isReady() const
{
    return true;
}

void Solution0005::describeIssue() const
{
    logWarn() << "Longest Palindromic Substring";
}

void Solution0005::run()
{
    std::string checkingString{"123bbbbbbbbbbbbaaaaaaaaabbbbbbbbbbbbbbbbbbb321"};

    logVerbose() << "Input params:";
    logVerbose() << "   1) string : " << checkingString;

    const auto palindrome = longestPalindrome(checkingString);
    logWarn() << "The palindrome is   : " << palindrome;
}

std::string Solution0005::longestPalindrome(const std::string& s)
{
    const int size = s.size();
    std::string palindrome{s[0]};
    int startPalindromeIndex = 0;
    char startPalindromeChar = s[startPalindromeIndex];
    int endPalindromeIndex = size - 1;

    while (startPalindromeIndex < size - palindrome.size()) {
        // find equal letters
        while (startPalindromeChar != s[endPalindromeIndex]) {
            --endPalindromeIndex;
        }

        const auto newPalindromeSize = endPalindromeIndex - startPalindromeIndex + 1;
        if (palindrome.size() < newPalindromeSize) {
            int leftLetterIndex = startPalindromeIndex + 1;
            int rightLetterIndex = endPalindromeIndex - 1;
            while (leftLetterIndex < rightLetterIndex) {
                if (s[leftLetterIndex] != s[rightLetterIndex]) {
                    break;
                }
                ++leftLetterIndex;
                --rightLetterIndex;
            }
            if (leftLetterIndex >= rightLetterIndex) {
                palindrome = s.substr(startPalindromeIndex, newPalindromeSize);
                ++startPalindromeIndex;
                startPalindromeChar = s[startPalindromeIndex];
                endPalindromeIndex = size - 1;
                continue; // while for startPalindromeIndex
            }
        }

        endPalindromeIndex -= 1;
        if ((startPalindromeIndex >= endPalindromeIndex)
            || (palindrome.size() > endPalindromeIndex - startPalindromeIndex + 1)) {
            ++startPalindromeIndex;
            startPalindromeChar = s[startPalindromeIndex];
            endPalindromeIndex = size - 1;
        }
    }

    return palindrome;
}