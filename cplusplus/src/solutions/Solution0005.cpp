#include "Solution0005.hpp"

#include <utils/helper.hpp>

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
    std::cout << "[Issue 0003] Longest Substring Without Repeating Characters" << std::endl;
}

void Solution0005::run()
{
    std::string checkingString{"babad"};

    std::cout << "\nInput params:" << std::endl;
    std::cout << "\t1) string : " << checkingString << std::endl;

    const auto palindrome = longestPalindrome(checkingString);
    std::cout << "The palindrome is   : " << palindrome << std::endl;
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
        if (startPalindromeIndex >= endPalindromeIndex) {
            ++startPalindromeIndex;
            startPalindromeChar = s[startPalindromeIndex];
            endPalindromeIndex = size - 1;
        }
    }

    return palindrome;
}