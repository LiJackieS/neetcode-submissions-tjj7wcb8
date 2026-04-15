class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 1;
        int cur = 1;
        if (s.size() == 0) {
            return 0;
        }
        unordered_set<char> set;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            while (set.count(s[r])) {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            res = max(r - l + 1, res);
        }
        return res;
    }
};
