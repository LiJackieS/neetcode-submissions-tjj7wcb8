class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res; // nums = {-4,-1,-1,0,1,2}

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0) {
                if (nums[i] == nums[i-1]) {
                    continue;
                }
            }

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int target = nums[l] + nums[r] + nums[i];
                if (target > 0) {
                    r--;
                }
                else if (target < 0) {
                    l++;
                }
                else if (target == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < nums.size() && nums[l] == nums[l-1]) {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
