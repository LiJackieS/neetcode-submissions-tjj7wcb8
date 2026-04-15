class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dup = []

        for x in nums:
            if x not in dup:
                dup.append(x)
            else:
                return True
        return False