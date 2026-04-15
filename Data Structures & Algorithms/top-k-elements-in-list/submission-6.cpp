struct Comp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> count;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq;

        for (int num : nums) {
            count[num]++;
        }
        for (const auto& pair : count) {
            pq.push(pair);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
