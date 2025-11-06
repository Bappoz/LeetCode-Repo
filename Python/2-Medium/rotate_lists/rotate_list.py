# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        
        if not head:
            return head

        current = head
        count = 1

        while current.next:
            count += 1
            current = current.next

        current.next = head

        k = k % count
        steps = count - k - 1

        tail = head
        
        for _ in range(steps):
            tail = tail.next

        new_head = tail.next
        tail.next = None

        return new_head
        