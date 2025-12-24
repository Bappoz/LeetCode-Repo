class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):

    def hasPathSum(self, root, targetSum):
        if not root: 
            return False
        return self.pathfinder(root, targetSum, 0)

    def pathfinder(self, root, targetSum, currentSum):
        currentSum += root.val

        if not root.left and not root.right:
            return currentSum == targetSum
        
        left_root = False
        right_root = False

        if root.left:
            left_root = self.pathfinder(root.left, targetSum, currentSum)

        if root.right:
            right_root = self.pathfinder(root.right, targetSum, currentSum)

        return left_root or right_root