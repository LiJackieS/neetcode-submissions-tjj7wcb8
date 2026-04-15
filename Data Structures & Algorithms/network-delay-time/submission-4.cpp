class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> edges;
        for (const auto& time : times) {
            edges[time[0]].push_back({time[1], time[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        int t = 0;
        minHeap.push({0,k});
        unordered_set<int> visited;

        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int node1 = top.second;
            int weight1 = top.first;
            if (visited.count(node1)) continue;

            visited.insert(node1);
            t = weight1;
            if (edges.count(node1)) {
                for (const auto& edge : edges[node1]) {
                    if (!visited.count(edge.first)) {
                        minHeap.push({edge.second + weight1, edge.first});
                    }
                }
            }
        }
        if (visited.size() == n) {
            return t;
        }
        return -1;
    }
};
