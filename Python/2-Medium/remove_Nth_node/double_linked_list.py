class ListNode(object):
    def __init__(self, val=0, next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        if not head:
            return None


        current = head
                
        while current:
            if current.next is None:
                tail = current
            current = current.next

        current = tail
        count = 1
        while current and count < n:
            current = current.prev
            count += 1
        
        if not current:
            return head

        if not current.prev:
            head = current.next
            if head:
                head.prev = None

        elif not current.next:
            current.prev.next = None

        else: 
            current.prev.next = current.next
            current.next.prev = current.prev

        return head

            