class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> queue;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    queue.push({i, j});
                }
            }
        }
        vector<vector<int>> dirs = {{-1, 0}, {1, 0},
                                    {0, -1}, {0, 1}};

        while (!queue.empty()) {
            int row = queue.front().first;
            int col = queue.front().second;
            queue.pop();

            for (int i = 0; i < 4; i++) {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != INT_MAX) {
                    continue;
                }
                grid[r][c] = grid[row][col] + 1;
                queue.push({r,c});
            }
        }
    }
};
