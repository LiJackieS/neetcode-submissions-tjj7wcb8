class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int max_num = 0;
        int cur_num = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while (hash.find(num) != hash.end()) {
                cur_num++;
                num++;
            }
            max_num = max(cur_num, max_num);
            cur_num = 0;
        }
        return max_num;
    }
};
