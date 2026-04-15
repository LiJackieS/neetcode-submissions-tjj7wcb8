class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtrack(cur, nums, 0);
        return res;
    }
    void backtrack(vector<int> cur, vector<int>& nums, int i) {
        if (i >= nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        backtrack(cur, nums, i + 1);
        cur.pop_back();
        backtrack(cur, nums, i + 1);
    }
};
