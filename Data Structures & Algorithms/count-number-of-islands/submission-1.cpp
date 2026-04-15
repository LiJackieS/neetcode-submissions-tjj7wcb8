class Solution {
public:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid,i,j);
                    island++;
                }
            }
        }
        return island;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int,int>> queue;
        grid[r][c] = '0';
        queue.push({r,c});
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            grid[cur.first][cur.second] = '0';
            for (auto dir : directions) {
                int first = cur.first + dir[0];
                int second = cur.second + dir[1];
                if (first < grid.size() && first >= 0 && second < grid[0].size() && second >= 0 && grid[first][second] == '1') {
                    queue.push({first,second});
                    grid[first][second] = '0';
                }
            } 
        }
    }
};
