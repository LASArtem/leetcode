#include "SpecialTask001.hpp"

#include <time.h>

#include <cstdlib>

SpecialTask001::SpecialTask001()
    : ISolution()
{
}

bool SpecialTask001::isReady() const
{
    return true;
}

void SpecialTask001::describeIssue() const
{
    logWarn() << "Find closest squared distance";
}

void SpecialTask001::run()
{
    srand(time(0));

    const int size = 1000;
    int x[size];
    int y[size];
    // int xCopy[size];
    // int yCopy[size];
    logVerbose() << "size: " << size << " points";
    for (int i = 0; i < size; ++i) {
        x[i] = rand() % 100000;
        // xCopy[i] = x[i];
        y[i] = rand() % 100000;
        // yCopy[i] = y[i];
        // logVerbose() << "point #" << i << ": {" << x[i] << ", " << y[i] << "}";
    }
    logVerbose() << "===========================================";

    const auto smallestDistanceByX = closestSquaredDistance(x, y, size);
    // const auto smallestDistanceByY = closestSquaredDistance(yCopy, xCopy, size);

    logWarn() << "smallestDistanceByX: " << smallestDistanceByX;
    // logWarn() << "smallestDistanceByY: " << smallestDistanceByY;

    // if (smallestDistanceByX != smallestDistanceByY) {
    //     logError() << "smallestDistanceByX != smallestDistanceByY";
    // }
}

int SpecialTask001::closestSquaredDistance(int x[], int y[], int n)
{
    int smallestDistance = 10000;
    int startIndex = 0;
    do {
        // find the lowerst point and move it to the start point
        int lowestPoint = startIndex;
        for (int i = startIndex + 1; i < n; ++i) {
            if (x[i] < x[lowestPoint]) {
                lowestPoint = i;
            }
        }

        if (startIndex != lowestPoint) {

            // logWarn() << "Swap points:  point #" << startIndex << ": {" << x[startIndex] << ", "
            //           << y[startIndex] << "} and point #" << lowestPoint << ": {" <<
            //           x[lowestPoint]
            //           << ", " << y[lowestPoint] << "}";

            int temp = x[startIndex];
            x[startIndex] = x[lowestPoint];
            x[lowestPoint] = temp;

            temp = y[startIndex];
            y[startIndex] = y[lowestPoint];
            y[lowestPoint] = temp;
        }

        // find new distance between points
        for (int i = startIndex + 1; i < n; ++i) {
            x[i] -= x[startIndex];
            y[i] -= y[startIndex];

            // logVerbose() << "startIndex: " << startIndex << ". point #" << i << ": {" << x[i]
            //              << ", " << y[i] << "}";

            int smallestDistanceInPreviousIteration = x[i] + (y[i] < 0 ? -y[i] : y[i]);
            if (smallestDistanceInPreviousIteration < smallestDistance) {
                smallestDistance = smallestDistanceInPreviousIteration;

                // logWarn() << "startIndex: " << startIndex
                //           << ". Updated smallestDistance: " << smallestDistance;
            }
        }

        // move start index
        // if (smallestDistance == 0) {
        //     logWarn() << "startIndex: " << startIndex << ". break";
        //     break;
        // } else {
        ++startIndex;
        // }
        // logVerbose() << "===========================================";
    } while (startIndex < (n - 1));

    return smallestDistance;
}