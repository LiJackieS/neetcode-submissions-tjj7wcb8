class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 1;
        unordered_set<char> set;
        if (s.size() == 0) {
            return 0;
        }
        for (int r = 0; r < s.size(); r++) {
            while (set.count(s[r])) {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
