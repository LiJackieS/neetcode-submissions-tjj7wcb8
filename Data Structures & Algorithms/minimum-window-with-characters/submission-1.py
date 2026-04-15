class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == '':
            return ''
        
        countT, window = {}, {}

        res, resLen = [-1,-1], float('inf')

        l = 0

        for c in t:
            countT[c] = countT.get(c, 0) + 1

        have, need = 0, len(countT)
        
        for r in range(len(s)):
            window[s[r]] = window.get(s[r], 0) + 1

            if s[r] in countT and window[s[r]] == countT[s[r]]:
                have += 1

            while have == need:
                if (r - l + 1) < resLen:
                    res = [l, r]
                    resLen = (r - l + 1)
                window[s[l]] -= 1

                if s[l] in countT and window[s[l]] < countT[s[l]]:
                    have -= 1
                l += 1
        l , r = res
        if resLen != float('inf'):
            return s[l : r + 1]
        else:
            return ''


            
 