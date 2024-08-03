# GFG Question :
class Solution:
    def productExceptSelf(self, nums):
        n = len(nums)
        if n == 0:
            return []

        # Initialize the left and right arrays
        left = [1] * n
        right = [1] * n

        # Construct the left array
        for i in range(1, n):
            left[i] = left[i - 1] * nums[i - 1]

        # Construct the right array
        for i in range(n - 2, -1, -1):
            right[i] = right[i + 1] * nums[i + 1]

        # Construct the product array P
        P = [1] * n
        for i in range(n):
            P[i] = left[i] * right[i]

        return P
