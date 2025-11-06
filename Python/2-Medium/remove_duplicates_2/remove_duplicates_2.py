class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head:
            return head

        ## Ordena a Lista primeiro
        tail = head
        while tail.next:
            if tail.val > tail.next.val:
                tmp = tail.next.val
                tail.next.val = tail.val
                tail.val = tmp
            tail = tail.next
        
        ## retiro as duplicadas

        dummy = ListNode(0, head)
        seen = set()
        duplicates = set()
        
        curr = dummy.next

        while curr:
            if curr.val in seen:
                duplicates.add(curr.val)
            else:
                seen.add(curr.val)
            curr = curr.next

        curr = dummy
        
        while curr.next:
            if curr.next.val in duplicates:
                curr.next = curr.next.next
            else:
                curr = curr.next
            
        return dummy.next