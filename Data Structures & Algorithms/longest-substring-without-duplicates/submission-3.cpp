class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = 0;
        unordered_set<char> set;
        int l = 0;
        int r = 0;

        while (r < s.size()) {
            if (set.find(s[r]) != set.end()) {
                set.erase(s[l]);
                l++;
            }
            else {
                set.insert(s[r]);
                size = max(r-l + 1, size);
                r++;
            }
        }
        return size;
    }
};
