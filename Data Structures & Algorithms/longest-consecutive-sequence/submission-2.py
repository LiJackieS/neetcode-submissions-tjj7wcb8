class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        max_length = 1
        for i in range(len(nums)):
            length = 1
            num = nums[i]
            while num + 1 in nums:
                num += 1
                length += 1
            max_length = max(length, max_length)
            
            
        return max_length
            

            