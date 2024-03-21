"""
0005 Longest Palindromic Substring
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
"""

from solutions.ISolution import ISolution

class Solution0005(ISolution):
    def isReady(self):
        return True
    
    def describeIssue(self):
        print("[Solution 0005]: Longest Palindromic Substring")

    def run(self):
        checkingString = "123bbbbbbbbbbbbaaaaaaaaabbbbbbbbbbbbbbbbbbb321"
        print(f'Input params:')
        print(f'    1) string: {checkingString}')
        palindrome = self.longestPalindrome(checkingString)
        print(f'The palindrome is: {palindrome}')

    def longestPalindrome(self, s: str) -> str:
        S_LENGTH = len(s)
        palindrome = s[0]

        startPalindromeIndex = 0
        endPalindromeIndex = S_LENGTH - 1
        while startPalindromeIndex < S_LENGTH - len(palindrome):
            # find equal letters
            while s[startPalindromeIndex] != s[endPalindromeIndex]:
                endPalindromeIndex -= 1

            newPalindromeSize = endPalindromeIndex - startPalindromeIndex + 1
            if startPalindromeIndex >= endPalindromeIndex or len(palindrome) >= newPalindromeSize:
                startPalindromeIndex += 1
                endPalindromeIndex = S_LENGTH - 1
            else:
                newPalindrome = s[startPalindromeIndex:endPalindromeIndex+1]
                if newPalindrome == newPalindrome[::-1] :
                    palindrome = newPalindrome
                    startPalindromeIndex += 1
                    endPalindromeIndex = S_LENGTH - 1
                else:
                    endPalindromeIndex -= 1

        return palindrome