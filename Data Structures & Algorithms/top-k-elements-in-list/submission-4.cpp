class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> queue;
        unordered_map<int, int> count;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]] += 1;
        }

        for (const auto& pair : count) {
            queue.push({pair.second, pair.first});
            if (queue.size() > k) {
                queue.pop();
            }
        }

        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(queue.top().second);
            queue.pop();
        }
        return res;
    }
};
