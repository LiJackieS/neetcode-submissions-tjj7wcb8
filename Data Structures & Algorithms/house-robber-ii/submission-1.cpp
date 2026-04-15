class Solution {
public:
    int rob_max(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        for (const auto& num : nums) {
            int temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {
        vector<int> rob1(nums.begin() + 1, nums.end());
        vector<int> rob2(nums.begin(), nums.end() - 1);
        return max(nums[0], max(rob_max(rob1), rob_max(rob2)));
    }
};
