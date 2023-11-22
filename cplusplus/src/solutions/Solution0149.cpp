#include "Solution0149.hpp"

#include <iostream>
#include <list>
#include <map>

Solution0149::Solution0149()
    : ISolution{}
{
}

bool Solution0149::isReady() const
{
    return true;
}

void Solution0149::describeIssue() const
{
    logWarn() << "Max Points on a Line";
}

void Solution0149::run()
{
    std::vector<std::vector<int>> points{{4, 5}, {4, -1}, {4, 0}};

    logVerbose() << "Input params:";
    logVerbose() << "      points: " << points;

    const int pointNumberAtLine = maxPoints(points);
    logWarn() << "pointNumberAtLine: " << pointNumberAtLine;
}

int Solution0149::maxPoints(std::vector<std::vector<int>>& points)
{
    int maxPointsInLine = points.size();
    const auto pointsSize = points.size();

    if (points.size() > 2) {
        maxPointsInLine = 2;
        int baseIndex = 0;
        do {
            const auto& basePoint = points[baseIndex];
            const int baseX = basePoint[0];
            const int baseY = basePoint[1];

            std::map<float, int> koefficients;
            for (int j = baseIndex + 1; j < pointsSize; ++j) {
                const auto& point = points[j];
                const auto x = point[0];
                const auto y = point[1];
                float k = 0.0;
                if (baseX == x) {
                    k = 60000; // near 2^16
                } else if (baseY == y) {
                    k = 0;
                } else {
                    k = static_cast<float>(baseY - y) / (baseX - x);
                }
                koefficients[k] += 1;

                if (koefficients[k] == maxPointsInLine) {
                    ++maxPointsInLine;
                }
            }
            ++baseIndex;
        } while (pointsSize - baseIndex > maxPointsInLine);
    }

    return maxPointsInLine;
}