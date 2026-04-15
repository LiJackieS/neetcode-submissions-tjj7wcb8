class Solution {
public:
    unordered_map<int,int> dp;
    int jump(vector<int>& nums) {
        return dfs(nums, 0);
    }
    int dfs(vector<int>& nums, int i) {
        if (dp.count(i)) {
            return dp[i];
        }
        if (i == nums.size() - 1) {
            return 0;
        }
        if (nums[i] == 0) {
            return 100000;
        }
        
        int res = 100000;
        int end = min((int)nums.size(), i + nums[i] + 1);
        for (int j = i + 1; j < end; j++) {
            res = min(res, 1 + dfs(nums, j));
        }
        dp[i] = res;
        return res;
    }
};
