class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> x;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (x.find(diff) != x.end()) {
                return {x[diff], i};
            }
            x[nums[i]] = i;
        }
        return {-1,-1};
    }
        
};
