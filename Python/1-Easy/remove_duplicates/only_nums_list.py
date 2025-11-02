class Solution(object):
    def removeDuplicate(self, nums):
        if not nums:
            return 0
        
        k = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[k] = nums[i]
                k += 1 

        nums = nums[:k]
        return k, nums
    
def main():
    nums = [1,1,1,1,2,2,2,2,3,3,3,4,5,5]
    solution = Solution()
    k, nums = solution.removeDuplicate(nums)

    print(f'k = {k} and nums_list is now: {nums}')

if __name__ == "__main__":
    main()