class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (string s : strs) {
            vector<int> count(26,0);
            for (char c : s) {
                count[c-'a'] += 1;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += " " + to_string(count[i]);
            }
            map[key].push_back(s);
        }

        for (const auto& pair : map) {
            res.push_back(pair.second);
        }
        return res;
    }
};
