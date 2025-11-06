class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        if not head or k <= 1:
            return head
        
        tail = head
        count = 0
        while tail:
            count += 1
            tail = tail.next
        
        if k > count:
            return None
        
        dummy = ListNode(0)
        dummy.next = head
        prev_group_end = dummy


        while True:
            k_size = prev_group_end
            for _ in range(k):
                k_size = k_size.next
                if not k_size:
                    return dummy.next
            
            group_start = prev_group_end.next
            next_group = k_size.next

            current = group_start
            prev = next_group
            for _ in range(k):
                proximo = current.next
                current.next = prev
                prev = current
                current = proximo

            prev_group_end.next = prev
            prev_group_end = group_start