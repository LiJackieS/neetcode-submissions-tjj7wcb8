class Solution {
public:
    vector<vector<int>> dp;
    int totalSum;
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        dp.resize(nums.size(), vector<int>(totalSum * 2 + 1, INT_MIN));
        return dfs(0, 0, nums, target);
    }

    int dfs(int i, int total, vector<int>& nums, int target) {

        if (i == nums.size()) {
            return total == target;
        }
        if (dp[i][total + totalSum] != INT_MIN) {
            return dp[i][total + totalSum];
        }
        dp[i][total + totalSum] = dfs(i + 1, total + nums[i], nums, target) + dfs(i + 1, total - nums[i], nums, target);
        return dp[i][total + totalSum];
    }
};
