class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_count(26,0);
        vector<int> t_count(26,0);

        for (char c : s) {
            s_count[c-'a'] += 1;
        }
        for (char c : t) {
            t_count[c-'a'] += 1;
        }
        return s_count == t_count;
    }
};
