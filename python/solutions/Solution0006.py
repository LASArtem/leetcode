"""
0006 Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"

Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
"""

from solutions.ISolution import ISolution

class Solution0006(ISolution):
    def isReady(self):
        return True
    
    def describeIssue(self):
        print("[Solution 0006]: Zigzag Conversion")

    def run(self):
        checkingString = "PAYPALISHIRING"
        numRows = 4
        print(f'Input params:')
        print(f'    1) string : {checkingString}')
        print(f'    2) numRows: {numRows}')
        zigzag = self.convert(checkingString, numRows);
        print(f'The Zigzag Conversion is: {zigzag}')
        print(f'The Zigzag is equal     : {zigzag == "PINALSIGYAHRPI"}')

    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        
        S_LENGTH = len(s)
        zigzag_string = ""
        for i in range(numRows):
            current_char_position = i
            if i == 0 or i == numRows-1:
                char_delta = 2 * (numRows - 1)
                while current_char_position < S_LENGTH:
                    zigzag_string +=s[current_char_position]
                    current_char_position += char_delta
            else:
                first_char_delta = 2 * (numRows - 1 - i)
                second_char_delta = 2 * i
                while current_char_position < S_LENGTH:
                    zigzag_string +=s[current_char_position]
                    current_char_position += first_char_delta
                    if current_char_position < S_LENGTH:
                        zigzag_string +=s[current_char_position]
                        current_char_position += second_char_delta
        return zigzag_string