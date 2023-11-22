#include "Solution1535.hpp"

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
    logWarn() << "Find the Winner of an Array Game";
}

void Solution1535::run()
{
    std::vector<int> arr{1, 11, 22, 33, 44, 55, 66, 77, 88, 99};
    const int expectedWins = 1000;

    logVerbose() << "Input params:";
    logVerbose() << "     1) arr : " << arr;
    logVerbose() << "     2) wins: " << expectedWins;

    const int winner = getWinner(arr, expectedWins);

    logWarn() << "The winner is: " << winner;
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

    logDebug() << "winCounter=" << winCounter;
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