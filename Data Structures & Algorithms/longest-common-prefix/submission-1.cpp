class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0; i < strs[0].size(); i++) {
            for (const auto& s : strs) {
                if (i == s.size() || strs[0][i] != s[i]) {
                    return s.substr(0, i);
                }
            }
        }
        return strs[0];
    }
};