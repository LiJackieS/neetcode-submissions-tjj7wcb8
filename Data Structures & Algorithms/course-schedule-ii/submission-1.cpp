class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indegree(numCourses);

        for (const auto& pre : prerequisites) {
            edges[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            indegree[node]--;

            res.push_back(node);
            for (const auto& nei : edges[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        if (res.size() == numCourses) {
            return res;
        }
        return {};
    }
};
