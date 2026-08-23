class DSU {
private:
    vector<int> parent;
    vector<int> rank;

    int find(int node) {
        if (node != parent[node]) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        std::iota(parent.begin(), parent.end(), 0);
    }
    bool unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            return false;
        }

        if (rank[pv] > rank[pu]) {
            swap(pu, pv);
        }

        rank[pu] += rank[pv];
        parent[pv] = pu;

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int n = edges.size();

        DSU dsu(n + 1);

        for (const auto& edge : edges) {
            if (!dsu.unionSet(edge[0], edge[1])) {
                res = {edge[0], edge[1]};
            }
        }


        return res;
    }
};
