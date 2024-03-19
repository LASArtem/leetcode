"""
0003. Longest Substring Without Repeating Characters

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
"""

from solutions.ISolution import ISolution

class Solution0003(ISolution):
    def isReady(self):
        return True
    
    def describeIssue(self):
        print("[Solution 0003]: Longest Substring Without Repeating Characters")

    def run(self):
        checkingString = "abcabcbb"
        print(f'Input params:')
        print(f'    1) string: {checkingString}')
        maxLength = self.lengthOfLongestSubstring(checkingString);
        print(f'The length is: {maxLength}')

    def lengthOfLongestSubstring(self, s: str) -> int:
        S_LENGTH = len(s)
        longest_substring_size = 0
        if S_LENGTH != 0 :
            letter_indexes = [-1] * 255
            subsctring_start_index = 0
            i = 0
            while i < S_LENGTH :
                letter = ord(s[i])
                if letter_indexes[letter] >= subsctring_start_index :
                    subsctring_start_index = letter_indexes[letter] + 1
                letter_indexes[letter] = i
                longest_substring_size = max(longest_substring_size, i - subsctring_start_index + 1)
                i += 1
        return longest_substring_size