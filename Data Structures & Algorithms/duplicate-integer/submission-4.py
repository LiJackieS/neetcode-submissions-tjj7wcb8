class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dup = []

        for num in nums:
            if num in dup:
                return True
            else:
                dup.append(num)
        return False