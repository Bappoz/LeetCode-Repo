class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n <= 2:
            return n

        a, b = 1, 2

        for i in range(3, n+1):
            new_b = a + b
            a = b
            b = new_b

        return b 
        
        