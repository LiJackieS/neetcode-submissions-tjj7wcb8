class Solution {
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size(), vector<int>(amount + 1, -1));
        sort(coins.begin(), coins.end());
        return dfs(0, amount, coins);
    }
    int dfs(int i, int a, vector<int>& coins) {
        if (a == 0) {
            return 1;
        }
        if (i >= coins.size()) {
            return 0;
        }
        if (dp[i][a] != -1) {
            return dp[i][a];
        }
        int res = 0;
        if (a >= coins[i]) {
            res = dfs(i + 1, a, coins) + dfs(i, a - coins[i], coins);
        }
        dp[i][a] = res;
        return res;
    }
};
