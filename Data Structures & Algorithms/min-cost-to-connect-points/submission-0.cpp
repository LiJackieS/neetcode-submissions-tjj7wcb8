class DSU {
private: 
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 1);
    }

    int find(int node) {
        if (node != parent[node]) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    bool unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            return false;
        }

        if (rank[pu] < rank[pv]) {
            swap(pu, pv);
        }

        rank[pu] += rank[pv];

        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<array<int, 3>> edges;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({distance, i, j});
            }
        }

        std::ranges::sort(edges);
        int res = 0;
        DSU dsu(n);

        for (int i = 0; i < edges.size(); ++i) {
            if (dsu.unionSet(edges[i][1], edges[i][2])) {
                res += edges[i][0];
            }
        }
        return res;
    }
};
