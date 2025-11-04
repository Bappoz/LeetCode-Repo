class Solution(object):
    def mySqrt(self, x):
        
        if x < 2:
            return x

        left = 1    
        right = x // 2  

        while left <= right:

            mid = (left + right)//2

            if (mid*mid) == x:
                return mid

            elif (mid*mid) < x:
                left = mid + 1

            if (mid*mid) > x:
                right = mid -1

        return right