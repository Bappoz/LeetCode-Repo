class Solution(object):
    def remove_duplicate(self, nums):

        seen = set()
        result = []

        for i in nums:
            if i not in seen:
                seen.add(i)
                result.append(i)

        nums[:] = result
        k = len(nums)
        return k, nums
    
def main():
    nums = [1, 1, 1, 2, 2, 3]
    solution = Solution()
    k, nums = solution.remove_duplicate(nums)

    print(f'k = {k} and nums_list is now: {nums}')

if __name__ == "__main__":
    main()

    