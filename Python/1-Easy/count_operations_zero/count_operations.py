class Solution(object):
    def countOperations(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        if num1 == 0 or num2 == 0:
            return 0
        if num1 < num2:
            num1, num2 = num2, num1
        return num1 // num2 + self.countOperations(num1 % num2, num2)