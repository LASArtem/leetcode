#include "Solution.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* beginl1 = l1;
    int remainder = 0;

    do {
        l1->val += l2->val + remainder;
        if (l1->val >= 10) {
            remainder = 1;
            l1->val -= 10;
        } else {
            remainder = 0;
        }

        if ((l1->next == nullptr) || (l2->next == nullptr)) {
            break;
        }

        l1 = l1->next;
        l2 = l2->next;
    } while (true);

    if ((l1->next == nullptr) && (l2->next == nullptr)) {
        if (remainder == 1) {
            l1->next = new ListNode(1);
            remainder = 0;
        }
    } else if (l1->next == nullptr) {
        l1->next = l2->next;
        l2->next = nullptr;
    }
    l1 = l1->next;

    while (remainder > 0) {
        l1->val += remainder;
        if (l1->val == 10) {
            l1->val = 0;
            if (l1->next == nullptr) {
                l1->next = new ListNode(1);
                remainder = 0;
            }
        } else {
            remainder = 0;
        }
        l1 = l1->next;
    }

    return beginl1;
}

void Solution::addRemainder(int remainder, ListNode* l)
{
    while (remainder > 0) {
        l->val += remainder;
        if (l->next == nullptr) {
            if (l->val == 10) {
                l->val = 0;
                l->next = new ListNode(1);
            }
            break;
        } else if (l->val == 10) {
            l->val = 0;
            // remainder is equal to 1
            l = l->next;
        } else {
            break;
        }
    }
}

void Solution::printList(std::string name, ListNode* list)
{
    std::cout << name << "[";
    while (list != nullptr) {
        std::cout << list->val;
        if (list->next != nullptr) {
            std::cout << ", ";
        }
        list = list->next;
    }
    std::cout << "]" << std::endl;
}