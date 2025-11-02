class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        # Devo Retornar k = Número de valores na lista diferente de val

        k = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1

        return k

def main():

    nums = [3,2,2,3]
    val = 3
    sol = Solution()
    k = sol.removeElement(nums, val)
    print(k)

if __name__ == "__main__":
    main()
        