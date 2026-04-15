class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> edges;
        for (const auto& time : times) {
            edges[time[0]].push_back({time[1], time[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        minHeap.push({0, k});
        int t = 0;
        unordered_set<int> visited;
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int weight1 = curr.first;
            int node1 = curr.second;

            if (visited.count(node1)) {
                continue;
            }

            visited.insert(node1);
            t = weight1;

            if (edges.count(node1)) {
                for (const auto& neighbor : edges[node1]) {
                    int node2 = neighbor.first;
                    int weight2 = neighbor.second;
                    if (!visited.count(node2)) {
                        minHeap.push({weight1 + weight2, node2});
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
