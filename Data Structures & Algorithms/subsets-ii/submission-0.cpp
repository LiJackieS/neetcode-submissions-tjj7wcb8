class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, {}, 0);
        return res;
    }
    void backtrack(vector<int>& nums, vector<int> cur, int i) {
        if (i == nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        backtrack(nums, cur, i + 1);
        cur.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        backtrack(nums, cur, i + 1);
    }

};
