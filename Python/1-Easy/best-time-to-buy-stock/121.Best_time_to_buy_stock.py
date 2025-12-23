class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        if not prices:
            return 0

        max_transaction = 0
        min_price = prices[0]
            
        for price in prices:
            if price < min_price:
                min_price = price
            elif price - min_price > max_transaction:
                max_transaction = price - min_price
        
        return max_transaction
        