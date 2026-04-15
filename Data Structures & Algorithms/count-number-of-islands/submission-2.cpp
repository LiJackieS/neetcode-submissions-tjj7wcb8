class Solution {
public:
    vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int,int>> q;
        q.push({i,j});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            grid[x][y] = '0';

            for (const auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1') {
                    q.push({nx,ny});
                }
            }
        }
    }
};
