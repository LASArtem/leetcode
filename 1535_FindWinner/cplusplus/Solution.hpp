#pragma once

#include <list>
#include <vector>

class Solution {
public:
    int getWinner(std::vector<int>& arr, int k) const;

private:
    void moveSecondToEnd(std::list<int>& participants) const;
};