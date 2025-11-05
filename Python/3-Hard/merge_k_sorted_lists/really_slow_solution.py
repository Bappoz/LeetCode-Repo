class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        if not lists:
            return None
            
        merge_list = lists[0]

        for i in range(1, len(lists)):
            merge_list = self.check_lower_value(merge_list, lists[i])
        return merge_list

    
    def check_lower_value(self, list1, list2):
        dummy = ListNode(0)
        current = dummy
        while list1 and list2:
            if(list1.val < list2.val):
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next

        if list1:
            current.next = list1
        else:
            current.next = list2
        
        return dummy.next
