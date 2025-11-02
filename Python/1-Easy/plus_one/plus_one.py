class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        multiplier = 1
        valor_int = 0
        inverso = digits[::-1]

        for i in inverso:
            valor_int += i* multiplier
            multiplier *= 10

        valor_int += 1
        digits = []
        while valor_int != 0:
            resto = valor_int % 10 
            digits.append(resto)
            valor_int //= 10

        digits = digits[::-1]
        return digits


def main():
    nums = [5, 9, 9 ,9]
    solution = Solution()
    digits = solution.plusOne(nums)
    
    print(digits)
    

if __name__ == "__main__":
    main()