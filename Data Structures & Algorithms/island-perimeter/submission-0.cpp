class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = -1;

                    while (!q.empty()) {
                        auto [x,y] = q.front();
                        q.pop();
                        for (const auto& dir : directions) {
                            int nx = dir[0] + x;
                            int ny = dir[1] + y;

                            if (nx < 0 || nx >= grid.size()) {
                                res++;
                            }
                            if (ny < 0 || ny >= grid[0].size()) {
                                res++;
                            }
                            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
                                if (grid[nx][ny] == 0) {
                                    res++;
                                }
                                else if (grid[nx][ny] == 1){
                                    q.push({nx,ny});
                                    grid[nx][ny] = -1;
                                }
                            } 
                        }
                    }
                }
            }
        }
        return res;
    }
};