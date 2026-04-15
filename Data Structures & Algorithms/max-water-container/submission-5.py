class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights) - 1
        maxWater = min(heights[l], heights[r]) * (r - l)
        water = 0

        while l < r:
            if heights[l] < heights[r]:
                l += 1
            else:
                r -= 1
            water = min(heights[l], heights[r]) * (r - l)
            maxWater = max(water, maxWater)
        return maxWater