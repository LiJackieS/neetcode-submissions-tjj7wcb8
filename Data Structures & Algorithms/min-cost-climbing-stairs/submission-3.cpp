class Solution {
public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(), -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(vector<int>& cost, int i) {
        if (i >= cost.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        dp[i] = cost[i] + min(dfs(cost, i + 1), dfs(cost, i + 2));
        return dp[i];
    }
};
