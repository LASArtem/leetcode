#include "Solution1535.hpp"

#include <utils/helper.hpp>

#include <algorithm>
#include <iostream>

Solution1535::Solution1535()
    : ISolution{}
{
}

bool Solution1535::isReady() const
{
    return true;
}

void Solution1535::describeIssue() const
{
    std::cout << "[Issue 1535] Find the Winner of an Array Game" << std::endl;
}

void Solution1535::run()
{
    std::vector<int> arr{1, 11, 22, 33, 44, 55, 66, 77, 88, 99};
    const int expectedWins = 1000;

    std::cout << "\nInput params:" << std::endl;
    std::cout << "\t1) arr : " << common::utils::helper::vectorToString(arr) << std::endl;
    std::cout << "\t2) wins: " << expectedWins << std::endl;

    const int winner = getWinner(arr, expectedWins);

    std::cout << "\nThe winner is: " << winner << std::endl;
}

int Solution1535::getWinner(std::vector<int>& arr, int k) const
{
    std::list<int> participants{arr.begin(), arr.end()};
    k = (k < participants.size()) ? k : (participants.size() - 1);
    int winCounter = 0;
    do {
        auto itSecond = ++(participants.begin());
        if (participants.front() > *itSecond) {
            ++winCounter;
        } else {
            winCounter = 1;
            std::iter_swap(participants.begin(), itSecond);
        }
        moveSecondToEnd(participants);
    } while (winCounter != k);

    std::cout << "Solution1535::getWinner: winCounter=" << winCounter << std::endl;
    return participants.front();
}

void Solution1535::moveSecondToEnd(std::list<int>& participants) const
{
    const size_t containerSize = participants.size();
    if (containerSize > 2) {
        const auto firstElement = participants.front();
        participants.pop_front();
        const auto secondElement = participants.front();
        participants.pop_front();

        participants.push_front(firstElement);
        participants.push_back(secondElement);
    }
}