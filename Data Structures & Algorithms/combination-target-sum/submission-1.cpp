class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        backtrack(nums, target, 0, cur);
        return res;
    }

    void backtrack(vector<int>& nums, int target, int i, vector<int>& cur) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || nums.size() <= i) {
            return;
        }
        cur.push_back(nums[i]);
        backtrack(nums, target - nums[i], i, cur);
        cur.pop_back();
        backtrack(nums, target, i + 1, cur);
    }
};
