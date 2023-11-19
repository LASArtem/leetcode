#pragma once

#include <ostream>

struct ListNode {
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode* next);

    int val;
    ListNode* next;
};

std::ostream& operator<<(std::ostream& out, const ListNode& value);