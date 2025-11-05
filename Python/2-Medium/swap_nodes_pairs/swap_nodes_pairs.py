class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head:
            return None
            
        
        dummy = ListNode(0, head)
        current = dummy.next
        
        while current:
            if current.next == None:
                return dummy.next
            tmp = current.val
            current.val = current.next.val
            current.next.val = tmp

            current = current.next.next
        
        return dummy.next