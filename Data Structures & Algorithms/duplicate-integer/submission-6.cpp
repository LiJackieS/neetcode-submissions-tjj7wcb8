class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int> uni;

        for (int i = 0; i < nums.size(); i++) {
            uni.push_back(nums[i]);
            if (count(uni.begin(), uni.end(), nums[i]) > 1) {
                return true;
            }
        }
        return false;

    }
};
