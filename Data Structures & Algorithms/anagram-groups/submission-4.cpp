class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (const auto& s : strs) {
            vector<int> count(26,0);
            for (const auto& c : s) {
                count[c - 'a'] += 1;
            }
            string key = "";
            for (int i = 0; i < count.size(); i++) {
                key += ' ' + count[i] + ' ';
            }
            map[key].push_back(s);
        }
        vector<vector<string>> res;

        for (const auto& pair : map) {
            res.push_back(pair.second);
        }
        return res;
    }
};
