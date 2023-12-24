#include "Solution2956.hpp"

#include <set>

Solution2956::Solution2956()
    : ISolution()
{
}

bool Solution2956::isReady() const
{
    return true;
}

void Solution2956::describeIssue() const
{
    logWarn() << "Find Common Elements Between Two Arrays";
}

void Solution2956::run()
{
    std::vector<int> nums1{4, 3, 2, 3, 1};
    std::vector<int> nums2{2, 2, 5, 2, 3, 6};

    logVerbose() << "Input params:";
    logVerbose() << "    1) nums1: " << nums1;
    logVerbose() << "    2) nums2: " << nums2;

    // task call
    const auto commonElements = findIntersectionValues(nums1, nums2);
    logWarn() << "commonElements: " << commonElements;
}

std::vector<int> Solution2956::findIntersectionValues(
    std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::vector<int> commonElements{0, 0};

    const int nums1Size = nums1.size();
    for (int i = 0; i < nums1Size;) {
        bool isIntersectionFound = false;

        // check Intersection with array_2
        for (int j = 0; j < nums2.size(); ++j) {
            if (nums2.at(j) == nums1.at(i)) {
                isIntersectionFound = true;
                ++commonElements[1];
            }
        }

        // add first Intersection
        if (isIntersectionFound) {
            ++commonElements[0];
        }

        // clean up array_1
        for (int k = i + 1; k < nums1Size; ++k) {
            if (nums1.at(k) == nums1.at(i)) {
                nums1[k] = 0;
                if (isIntersectionFound) {
                    ++commonElements[0];
                }
            }
        }

        // move index
        while (++i < nums1Size && nums1.at(i) == 0) { }
    }

    return commonElements;
}

std::vector<int> Solution2956::findIntersectionValues_Solution1(
    std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::vector<int> commonElements{0, 0};
    std::set<int> uniqueElements;

    uniqueElements.insert(nums1.begin(), nums1.end());
    logVerbose() << "uniqueElements:" << uniqueElements;
    for (const auto element : nums2) {
        if (uniqueElements.find(element) != uniqueElements.end()) {
            ++commonElements[1];
        }
    }

    uniqueElements.clear();

    uniqueElements.insert(nums2.begin(), nums2.end());
    logVerbose() << "uniqueElements:" << uniqueElements;
    for (const auto element : nums1) {
        if (uniqueElements.find(element) != uniqueElements.end()) {
            ++commonElements[0];
        }
    }

    return commonElements;
}

std::vector<int> Solution2956::findIntersectionValues_Solution2(
    std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::vector<int> commonElements{0, 0};

    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            if (nums1[i] == nums2[j]) {
                ++commonElements[0];
                break;
            }
        }
    }

    for (int i = 0; i < nums2.size(); ++i) {
        for (int j = 0; j < nums1.size(); ++j) {
            if (nums2[i] == nums1[j]) {
                ++commonElements[1];
                break;
            }
        }
    }

    return commonElements;
}