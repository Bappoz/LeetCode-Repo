# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        
        if not head:
            return None

        seen = set()
        current = head
        prev = None

        while current:
            if current.val in seen:
                prev.next = current.next
                current = current.next
            else:
                seen.add(current.val)
                prev = current
                current = current.next
        
        return head

