class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_count(26,0);
        vector<int> t_count(26,0);
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            s_count[s[i]-'a']++;
            t_count[t[i]-'a']++;
        }
        return s_count == t_count;
    }
};
