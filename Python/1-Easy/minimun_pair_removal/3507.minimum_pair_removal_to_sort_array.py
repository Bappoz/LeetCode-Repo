class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):


    def minimumPairRemoval(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        def is_non_decreasing(head):
            curr = head
            while curr and curr.next:
                if curr.val > curr.next.val:
                    return False
                curr = curr.next
            return True
            
        if not nums:
            return 0

        min_operation = 0

        head = ListNode(nums[0])
        current = head

        for i in nums[1:]:
            current.next = ListNode(i)
            current = current.next
            
        while not is_non_decreasing(head):
            prev = None
            curr = head

            min_sum = float('inf')
            min_prev = None
            min_first = None

            while curr and curr.next:
                s = curr.val + curr.next.val
                if s < min_sum:
                    min_sum = s
                    min_prev = prev
                    min_first = curr
                prev = curr
                curr = curr.next

            new_node = ListNode(min_sum)

            if min_prev is None:
                # par começa na cabeça
                new_node.next = min_first.next.next
                head = new_node
            else:
                new_node.next = min_first.next.next
                min_prev.next = new_node

            min_operation += 1

        
        return  min_operation

            