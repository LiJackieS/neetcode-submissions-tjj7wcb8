class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        x = {}

        for i, num in enumerate(nums):
            y = target - num
            if y in x:
                return [x[y],i]
            x[num] = i
        return []

            