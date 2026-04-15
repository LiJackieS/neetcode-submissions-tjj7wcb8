class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string s : strs) {
            vector<int> count(26,0);

            for (char c : s) {
                count[c-'a']++;
            }
            string key = to_string(count[0]) + "_";
            for (int i = 1; i < 26; i++) {
                key += to_string(count[i]) + "_";
            }
            m[key].push_back(s);
        }
        for (const auto& s : m) {
            res.push_back(s.second);
        }
        return res;
    }
};
