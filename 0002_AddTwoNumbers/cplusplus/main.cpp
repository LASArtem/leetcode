#include "Solution.hpp"

#include <forward_list>
#include <iostream>

ListNode* createList(const int number);
void removeList(ListNode* list);
void printList(ListNode* list);

int main()
{
    const int number1 = 9999999;
    const int number2 = 9999;
    ListNode* listNumber1 = createList(number1);
    ListNode* listNumber2 = createList(number2);

    std::cout << "listNumber1: ";
    printList(listNumber1);
    std::cout << std::endl;

    std::cout << "listNumber2: ";
    printList(listNumber2);
    std::cout << std::endl;

    Solution solution;
    const auto listSum = solution.addTwoNumbers(listNumber1, listNumber2);

    std::cout << "listSum    : ";
    printList(listSum);
    std::cout << std::endl;

    removeList(listNumber1);
    removeList(listNumber2);
    return 0;
}

ListNode* createList(int number)
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

void removeList(ListNode* list)
{
    while (list != nullptr) {
        ListNode* tmp = list->next;
        delete list;
        list = tmp;
    }
}

void printList(ListNode* list)
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