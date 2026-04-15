class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> results(nums.size(), 1);
        int prefix = 1;
        int postfix = 1;

        for (int i = 0; i < nums.size(); i++) {
            results[i] = prefix;
            prefix *= nums[i];
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            results[i] *= postfix;
            postfix *= nums[i];
        }
        return results;
    }
};
