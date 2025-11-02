class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        left = 0
        right = len(nums) - 1
        
        while left <= right:

            middle = left + (right - left) // 2
            
            if nums[middle] == target:
                return middle

            elif target < nums[middle]:
                right = middle - 1
            elif target > nums[middle]:
                left = middle + 1

        return left

        
def main():
    nums = [1,3,5,6]
    solution = Solution()
    index = solution.searchInsert(nums, 0)

    print(index)

if __name__ == "__main__":
    main()