#include "Solution.hpp"
#include "helper.hpp"

#include <iostream>

int main()
{
    std::cout << "1535. Find the Winner of an Array Game" << std::endl;

    std::vector<int> arr{1, 11, 22, 33, 44, 55, 66, 77, 88, 99};
    const int expectedWins = 1000;

    std::cout << "\nInput params:" << std::endl;
    std::cout << "\t1) arr : " << helper::vectorToString(arr) << std::endl;
    std::cout << "\t2) wins: " << expectedWins << std::endl;

    Solution solution;
    const int winner = solution.getWinner(arr, expectedWins);

    std::cout << "\nThe winner is: " << winner << std::endl;

    return 0;
}