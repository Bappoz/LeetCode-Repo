class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def partition(self, head, x):
        """
        :type head: Optional[ListNode]
        :type x: int
        :rtype: Optional[ListNode]
        """
        
        if not head:
            return head

        dummy_less = ListNode(0)
        less = dummy_less

        dummy_greater = ListNode(0)
        greater = dummy_greater

        current = head

        while current:
            ## Cortar a ligação antes de conectar à nova lista
            proximo = current.next
            current.next = None

            if current.val < x:
                less.next = current
                less = less.next
            else:
                greater.next = current
                greater = greater.next

            current = proximo
        
        less.next = dummy_greater.next

        return dummy_less.next



