class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int> uni;
        for (int i = 0; i < nums.size(); i++) {
            uni.push_back(nums.at(i));
            if((count(uni.begin(),uni.end(),uni.at(i))) > 1) {
                return true;
            }
        }
        return false;
    }
};
