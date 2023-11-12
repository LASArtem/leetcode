#include "Solution0002.hpp"

#include <iostream>

Solution0002::Solution0002()
    : ISolution()
{
}

bool Solution0002::isReady() const
{
    return true;
}

void Solution0002::describeIssue() const
{
    std::cout << "[Issue 0002] Add Two Numbers" << std::endl;
}

void Solution0002::run()
{
    ListNode* listNumber1 = createList(9999999);
    std::cout << "listNumber1: ";
    printList(listNumber1);
    std::cout << std::endl;

    ListNode* listNumber2 = createList(9999);
    std::cout << "listNumber2: ";
    printList(listNumber2);
    std::cout << std::endl;

    // task call
    const auto listSum = addTwoNumbers(listNumber1, listNumber2);

    std::cout << "listSum    : ";
    printList(listSum);
    std::cout << std::endl;

    removeList(listNumber1);
    removeList(listNumber2);
}

ListNode* Solution0002::createList(int number)
{
    ListNode* start = new ListNode();

    auto node = start;
    do {
        node->val = number % 10;
        number = number / 10;
        if (number == 0) {
            break;
        }
        node->next = new ListNode();
        node = node->next;
    } while (true);

    return start;
}

void Solution0002::removeList(ListNode* list)
{
    while (list != nullptr) {
        ListNode* tmp = list->next;
        delete list;
        list = tmp;
    }
}

void Solution0002::printList(ListNode* list)
{
    std::cout << "[";
    while (list != nullptr) {
        std::cout << list->val;
        if (list->next != nullptr) {
            std::cout << ", ";
        }
        list = list->next;
    }
    std::cout << "]";
}

ListNode* Solution0002::addTwoNumbers(ListNode* l1, ListNode* l2)
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