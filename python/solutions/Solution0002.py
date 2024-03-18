"""
0002. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
  Input: l1 = [2,4,3], l2 = [5,6,4]
  Output: [7,0,8]
  Explanation: 342 + 465 = 807.
Example 2:
  Input: l1 = [0], l2 = [0]
  Output: [0]
Example 3:
  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
  Output: [8,9,9,9,0,0,0,1]

Constraints:
  The number of nodes in each linked list is in the range [1, 100].
  0 <= Node.val <= 9
  It is guaranteed that the list represents a number that does not have leading zeros.
"""

from solutions.ISolution import ISolution
from solutions.ListNode import ListNode


class Solution0002(ISolution):
    def isReady(self):
        return True
    
    def describeIssue(self):
        print("[Solution 0002]: Add Two Numbers")

    def run(self):
        listNumber1 = self.createList(999999)
        self.printListNumber("listNumber1", listNumber1)

        listNumber2 = self.createList(999)
        self.printListNumber("listNumber2", listNumber2)

        resultNumber = self.addTwoNumbers_secondTry(listNumber1, listNumber2);
        self.printListNumber("resultNumber", resultNumber)

    def createList(self, number: int) -> ListNode:
        node = ListNode(number%10)
        returnListNode = node
        while True:
            number = number // 10
            if number == 0 :
                break
            else :
                node.next = ListNode(number%10)
                node = node.next
        return returnListNode
    
    def printListNumber(self, name: str, l: ListNode):
        printString = "[" + str(l.val)
        while l.next != None:
            l = l.next
            printString += str(l.val)
        printString += "]"
        print(f'{name}: {printString}')

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        node = ListNode(l1.val + l2.val)
        returnList = node
        while l1.next != None or l2.next != None:
            if l1.next == None :
                l1.val = 0
            else:
                l1 = l1.next
            
            if l2.next == None :
                l2.val = 0
            else:
                l2 = l2.next
            node.next = ListNode(l1.val + l2.val + node.val // 10)
            node.val =  node.val % 10
            node = node.next
        else :
            if node.val > 9 :
                node.next = ListNode(1)
                node.val = node.val % 10
        return returnList
    
    def addTwoNumbers_secondTry(self, l1: ListNode, l2: ListNode) -> ListNode:
        returnList = l1
        reminder = 0

        while True:
            l1.val += l2.val + reminder
            if l1.val >= 10 :
                reminder = 1
                l1.val -= 10
            else :
                reminder = 0

            if l1.next == None or l2.next == None :
                break
            else:
                l1 = l1.next;
                l2 = l2.next;

        if l1.next == None and l2.next == None :
            if reminder == 1 :
                l1.next = ListNode(1)
                reminder = 0;
        elif l1.next == None :
            l1.next = l2.next
            l2.next = None

        l1 = l1.next;

        while reminder > 0 :
            l1.val += reminder;
            if l1.val == 10 :
                l1.val = 0
                if l1.next == None :
                    l1.next = ListNode(1)
                    reminder = 0
            else:
                reminder = 0
            l1 = l1.next;

        return returnList