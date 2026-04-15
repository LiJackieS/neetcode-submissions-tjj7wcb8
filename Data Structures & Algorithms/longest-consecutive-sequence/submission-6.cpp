class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        if (nums.size() == 0) {
            return 0; 
        }
        int res = 1;
        int cur = 1;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while (set.count(num + 1)) {
                num++;
                cur++;
            }
            res = max(cur, res);
            cur = 1;
        }
        return res;

    }
};
