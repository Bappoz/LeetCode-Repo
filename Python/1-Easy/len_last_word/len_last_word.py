class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        inverso = s[::-1]
        if inverso[0] == ' ':
            j = 0
            while inverso[j] == ' ':
                j += 1
            inverso = inverso[j:]

        for i in range(len(inverso)):
            if inverso[i] == ' ':
                return i

        return len(inverso)     