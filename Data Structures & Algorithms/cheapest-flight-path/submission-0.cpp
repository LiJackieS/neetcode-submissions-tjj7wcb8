class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));

        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;


        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        dist[src][0] = 0;
        pq.push({0,src,0});

        while (!pq.empty()) {
            auto [cost, cur, stops] = pq.top();
            pq.pop();

            if (cur == dst) {
                return cost;
            }

            if (cost > dist[cur][stops] || stops == k + 1) {
                continue;
            }

            for (const auto& [neiCur, neiCost] : adj[cur]) {
                int newPrice = neiCost + cost;
                int newStops = stops + 1;
                if (newPrice < dist[neiCur][newStops]) {
                    pq.push({newPrice, neiCur, newStops});
                    dist[neiCur][newStops] = newPrice;
                }
            }
        }

        return -1;

    }
};
