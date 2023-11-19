#include "Solution0007.hpp"

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

Solution0007::Solution0007()
    : ISolution{}
{
}

bool Solution0007::isReady() const
{
    return true;
}

void Solution0007::describeIssue() const
{
    logWarn() << "Reverse Integer";
}

void Solution0007::run()
{
    const int64_t inputNumber = 1563847412;

    logDebug() << "Input params:";
    logDebug() << "  1) inputNumber : " << inputNumber;

    const auto reversedNumber = reverse(inputNumber);
    logWarn() << "reversedNumber is: " << reversedNumber;
}

int Solution0007::reverse(int64_t x)
{
    int reversedNumber = 0;
    while (x != 0) {
        if ((x > 0) ? (reversedNumber > 214748364) : (reversedNumber < -214748364)) {
            reversedNumber = 0;
            break;
        }
        reversedNumber = reversedNumber * 10 + x % 10;
        x /= 10;
    }

    return reversedNumber;
}