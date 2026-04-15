class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int cur = 0;
        int res = INT_MAX;
        for (int r = 0; r < nums.size(); r++) {
            cur += nums[r];
            while (cur >= target) {
                res = min(res, r - l + 1);
                cur -= nums[l];
                l++;
            }
        }
        if (res == INT_MAX) return 0;
        return res;
    }
};