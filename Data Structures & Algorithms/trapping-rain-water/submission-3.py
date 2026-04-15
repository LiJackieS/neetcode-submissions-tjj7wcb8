class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) == 0:
            return 0

        l = 0
        r = len(height) - 1
        res = 0

        leftMax = height[l]
        rightMax = height[r]

        while l < r:
            if leftMax < rightMax:
                l += 1
                leftMax = max(height[l], leftMax)
                res += leftMax - height[l]
            else:
                r -= 1
                rightMax = max(height[r], rightMax)
                res += rightMax - height[r]
        return res
