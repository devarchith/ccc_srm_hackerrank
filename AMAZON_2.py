#You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

#You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#Input Format

#Given the Head of two linked lists

#Constraints

#The number of nodes in each linked list is in the range [1, 100].
#0 <= Node.val <= 9
#It is guaranteed that the list represents a number that does not have leading zeros.
#Output Format

#Return the Head of the Linked List

#Sample Input 0

#10 6
#0 8 2 8 6 7 2 8 7 2
#5 7 9 5 7 9
#Sample Output 0

#5 5 2 4 4 7 3 8 7 2
#Sample Input 1

#4 3
#8 1 1 6
#7 4 4
#Sample Output 1

#5 6 5 6
#solution:-
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    carry = 0
    dummy = ListNode()
    curr = dummy
    while l1 or l2 or carry:
        sum = carry
        if l1:
            sum += l1.val
            l1 = l1.next
        if l2:
            sum += l2.val
            l2 = l2.next
        carry = sum // 10
        curr.next = ListNode(sum % 10)
        curr = curr.next
    return dummy.next

def printList(head: ListNode) -> None:
    while head:
        print(head.val, end=" ")
        head = head.next

n1, n2 = map(int, input().split())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

# Create the first linked list
head1 = ListNode(arr1[0])
temp = head1
for i in range(1, n1):
    temp.next = ListNode(arr1[i])
    temp = temp.next

# Create the second linked list
head2 = ListNode(arr2[0])
temp = head2
for i in range(1, n2):
    temp.next = ListNode(arr2[i])
    temp = temp.next

# Add the two linked lists and print the result
result = addTwoNumbers(head1, head2)
printList(result)
