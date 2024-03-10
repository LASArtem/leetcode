#include "Solution2958.hpp"

#include <set>

Solution2958::Solution2958()
    : ISolution()
{
}

bool Solution2958::isReady() const
{
    return true;
}

void Solution2958::describeIssue() const
{
    logWarn() << "Length of Longest Subarray With at Most K Frequency";
}

void Solution2958::run()
{
    std::vector<int> nums = {3, 1, 1};
    int k = 1;

    logVerbose() << "Input params:";
    logVerbose() << "    1) nums: " << nums;
    logVerbose() << "    2) k   : " << k;

    // task call
    const auto length = maxSubarrayLength(nums, k);
    logWarn() << "length: " << length;
}

int Solution2958::maxSubarrayLength(std::vector<int>& nums, const int k)
{
    const int numsSize = nums.size();
    if (numsSize == 1 || k >= numsSize) {
        return numsSize;
    }

    int maxSubarray = 0;
    for (int i = 0; i < numsSize - maxSubarray; ++i) {
        int repeatCounter = 0;
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] == nums[j]) {
                ++repeatCounter;
            }

            if (repeatCounter == k) {
                if ((maxSubarray < j - i) && isSubarrayGood(nums, i + 1, j - 1, k)) {
                    maxSubarray = j - i;
                    logVerbose() << "maxSubarray: " << maxSubarray << " {" << i << ", " << j << "}";
                }
                break;
            }
        }

        if (repeatCounter != k) {
            if ((maxSubarray < numsSize - i) && isSubarrayGood(nums, i + 1, numsSize - 1, k)) {
                maxSubarray = numsSize - i;
                logVerbose() << "maxSubarray2: " << maxSubarray << " {" << i << ", " << numsSize - 1
                             << "}";
            }
        }
    }

    return maxSubarray;
}

bool Solution2958::isSubarrayGood(std::vector<int>& nums, int startPoint, int endPoint, int k)
{
    logMethod("isSubarrayGood", nums, startPoint, endPoint, k);
    if (startPoint > endPoint) {
        logVerbose() << "false_0";
        return false;
    } else if (startPoint == endPoint) {
        logVerbose() << "true_0";
        return true;
    }

    for (int i = startPoint; i < endPoint; ++i) {
        int repeatCounter = 0;
        for (int j = i + 1; j <= endPoint; ++j) {
            if (nums[i] == nums[j]) {
                ++repeatCounter;
            }

            if (repeatCounter == k) {
                logVerbose() << "false";
                return false;
            }
        }
    }
    logVerbose() << "true";
    return true;
}