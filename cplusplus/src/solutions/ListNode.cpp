#include "ListNode.hpp"

ListNode::ListNode()
    : val(0)
    , next(nullptr)
{
}

ListNode::ListNode(int x)
    : val(x)
    , next(nullptr)
{
}

ListNode::ListNode(int x, ListNode* next)
    : val(x)
    , next(next)
{
}

std::ostream& operator<<(std::ostream& out, const ListNode& value)
{
    return out << "{" << value.val << ", " << value.next << "}";
}