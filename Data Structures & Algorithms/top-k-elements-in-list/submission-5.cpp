struct pair_compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, pair_compare> pq;
        unordered_map<int,int> count;
        for (const auto& num : nums) {
            count[num]++;
        }
        for (const auto& pair : count) {
            pq.push(pair);
        }
        vector<int> res;

        while (!pq.empty() && res.size() < k) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
