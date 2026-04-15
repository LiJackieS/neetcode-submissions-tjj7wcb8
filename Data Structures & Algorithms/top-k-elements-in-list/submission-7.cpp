struct Comp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq;
        unordered_map<int,int> count;

        for (int num : nums) {
            count[num]++;
        }

        for (const auto& pair : count) {
            pq.push(pair);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;

        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
