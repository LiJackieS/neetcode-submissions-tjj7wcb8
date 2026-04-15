#include <ranges>
class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{0,-1},{-1,0}};
    bool path_exists(vector<vector<int>>& grid, int max_water, int i, int j) {
        queue<pair<int,int>> q;
        unordered_set<int> visited;

        q.push({i,j});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            visited.insert(grid[x][y]);

            for (const auto& dir : directions) {
                int nx = dir[0] + x;
                int ny = dir[1] + y;

                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid.size() && grid[nx][ny] <= max_water && !visited.count(grid[nx][ny])) {
                   if (nx == grid.size() - 1 && ny == grid.size() - 1) {
                    return true;
                   }
                   q.push({nx,ny});
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        auto flat_view = grid | std::views::join;

        vector<int> flat(flat_view.begin(), flat_view.end());

        int l = 0;
        int r = flat.size() - 1;
        sort(flat.begin(), flat.end());

        while (l < r) {
            int mid = (l + r) / 2;
            if (flat[mid] < grid[0][0]) {
                l = mid + 1;
                continue;
            }
            if (flat[mid] >= grid[0][0] && path_exists(grid, flat[mid], 0, 0)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return flat[r];
    }
};
