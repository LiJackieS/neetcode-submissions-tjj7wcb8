class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash = defaultdict(list)

        for char in strs:
            count = [0] * 26

            for c in char:
                count[ord(c) - ord("a")] += 1
            
            hash[tuple(count)].append(char)
        
        return hash.values()