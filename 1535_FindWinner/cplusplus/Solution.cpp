#include "Solution.hpp"

#include <algorithm>
#include <iostream>

int Solution::getWinner(std::vector<int>& arr, int k) const
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

    std::cout << "Solution::getWinner: winCounter=" << winCounter << std::endl;
    return participants.front();
}

void Solution::moveSecondToEnd(std::list<int>& participants) const
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