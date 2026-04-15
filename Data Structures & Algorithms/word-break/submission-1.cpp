class Solution {
public:
    unordered_map<int, bool> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        dp[s.size()] = true;
        return dfs(0, s, wordDict);
    }

    bool dfs(int i, string& s, vector<string>& wordDict) {
        if (dp.find(i) != dp.end()) {
            return dp[i];
        }

        for (const auto& word : wordDict) {
            if (i + word.size() <= s.size() && s.substr(i, word.size()) == word) {
                if (dfs(i + word.size(), s, wordDict)) {
                    dp[i] = true;
                    return true;
                }
            }
        }
        dp[i] = false;
        return false;
    }

};
