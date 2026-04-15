class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        for (const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for (auto& [src, dest] : adj) {
            sort(dest.rbegin(), dest.rend());
        }

        vector<string> res;
        stack<string> q;

        q.push("JFK");

        while (!q.empty()) {
            auto cur = q.top();
            if (!adj[cur].empty()) {
                q.push(adj[cur].back());
                adj[cur].pop_back();
            }
            else {
                q.pop();
                res.push_back(cur);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
