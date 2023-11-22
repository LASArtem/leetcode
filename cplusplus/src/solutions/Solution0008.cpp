#include "Solution0008.hpp"

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

Solution0008::Solution0008()
    : ISolution{}
{
}

bool Solution0008::isReady() const
{
    return true;
}

void Solution0008::describeIssue() const
{
    logWarn() << "String to Integer (atoi)";
}

void Solution0008::run()
{
    const std::string stringNumber{"21474836460"};

    logVerbose() << "Input params:";
    logVerbose() << "  1) stringNumber : " << stringNumber;

    const auto number = myAtoi(stringNumber);
    logWarn() << "number is: " << number;
}

int Solution0008::myAtoi(const std::string& s)
{
    /*
     * 32       -> space
     * 43       -> plus
     * 45       -> minus
     * 48-57    -> digits from 0 to 9
     */

    const int length = s.size();
    int number = 0;
    int index = 0;

    while (s[index] == 32) {
        ++index;
    }

    int sign = 1;
    if (s[index] == 45) {
        sign = -1;
        ++index;
    } else if (s[index] == 43) {
        ++index;
    }

    logDebug() << "index: " << index << "; sign: " << sign;
    if (index < length) {
        int digit = s[index] - 48;
        while (digit >= 0 && digit <= 9) {
            if (number == 214748364) {
                logError() << "number is overloaded [number = 214748364] digit=" << digit;
                if (++index == length || s[index] < 48 || s[index] > 57) {
                    return (sign == 1) ? INT_MAX - (digit > 7 ? 0 : 7 - digit)
                                       : INT_MIN + (digit > 8 ? 0 : (8 - digit));
                } else {
                    return (sign == 1) ? INT_MAX : INT_MIN;
                }
            } else if (number > 214748364) {
                logError() << "number is overloaded";
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            logDebug() << "number: " << number << "; index: " << index << "; digit: " << digit;
            number = number * 10 + digit;
            ++index;
            digit = (index == length) ? -1 : s[index] - 48;
        }
    }
    // return (number < 0) ? number : sign * number;
    return sign * number;
}