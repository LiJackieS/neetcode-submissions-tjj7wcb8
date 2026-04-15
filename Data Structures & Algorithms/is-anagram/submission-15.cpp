class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char,int> a;
        unordered_map<char,int> b;
        
        for (int i = 0; i < s.size(); i++) {
            a[s.at(i)] += 1;
            b[t.at(i)] += 1;
        }

        return a == b;
    }
};
