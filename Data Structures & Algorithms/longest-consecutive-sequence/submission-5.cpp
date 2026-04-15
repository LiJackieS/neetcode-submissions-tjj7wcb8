class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int max_count = 0;
        if (nums.empty()) {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            int x = nums[i];
            while (set.find(x+1) != set.end()) {
                x++;
                count++;
            }
            max_count = max(count, max_count);
        }
        return max_count + 1;
    }
};
