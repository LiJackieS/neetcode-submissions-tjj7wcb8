class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size() + 1);
        vector<int> res;

        for (int n : nums) {
            count[n]++;
        }

        for (const auto& c : count) {
            freq[c.second].push_back(c.first);
        }

        for (int i = freq.size() - 1; i >= 0; i--) {
            for (int num : freq[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res;
                }
            }
        }
    }
};
