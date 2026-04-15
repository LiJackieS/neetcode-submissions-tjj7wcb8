class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        res_1 = {}
        res_2 = {}

        for i in range(len(s)):
            res_1[s[i]] = res_1.get(s[i], 0) + 1
            res_2[t[i]] = res_2.get(t[i], 0) + 1

        return res_1 == res_2


        