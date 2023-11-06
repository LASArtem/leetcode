#include "Solution.hpp"

#include <iostream>
#include <string>

int main()
{
    std::cout << "0003. Longest Substring Without Repeating Characters" << std::endl;

    std::string checkingString{"ABCADEFG"};

    std::cout << "\nInput params:" << std::endl;
    std::cout << "\t1) string : " << checkingString << std::endl;

    Solution solution;
    const int maxLength = solution.lengthOfLongestSubstring(checkingString);

    std::cout << "\nThe substring is: " << solution.getLongestSubstring() << std::endl;
    std::cout << "The length is   : " << maxLength << std::endl;

    return 0;
}