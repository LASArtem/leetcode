/* Special 001. Find the squarted shortest distance

Find the squarted shortest distance between pairs of the randomly genrated points

Example 1:
  Input: x = [0,1,2], y = [0,1,4]
  Output: 2
  Explanation: The closest points is (0,0) and (1,1)
  Squarted distance: (1-0) + (1-0) = 2

Constraints:
  Points: 2 <= n <= 1000
  CoordinateX: 0 < x[i] < 100000
  CoordinateY: 0 < y[i] < 100000
*/

#pragma once

#include "ISolution.hpp"

#include <string>

class SpecialTask001 : public ISolution {
public:
    SpecialTask001();

    // ISolutions
    bool isReady() const override;
    void describeIssue() const override;
    void run() override;

    // Debuggable
    inline std::string buildPrefix() const override
    {
        return "[SpecialTask001]";
    }

private:
    int closestSquaredDistance(int x[], int y[], int n);
};