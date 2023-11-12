/*0149. Max Points on a Line

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane,
return the maximum number of points that lie on the same straight line.

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#pragma once

#include "ISolution.hpp"

#include <vector>

class Solution0149 : public ISolution {
public:
    Solution0149();

    // ISolutions
    bool isReady() const override;
    void describeIssue() const override;
    void run() override;

private:
    // call method
    int maxPoints(std::vector<std::vector<int>>& points);
};