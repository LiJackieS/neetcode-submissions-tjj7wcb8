class Solution {
public:
    vector<vector<int>> dp;
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();

        dp.resize(M, vector<int>(N, -1));
        return dfs(0, 0, grid);
    }
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();

        if (i >= M || j >= N) {
            return INT_MAX;
        }
        if (i == M - 1 && j == N - 1) {
            return grid[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        dp[i][j] = grid[i][j] + min(dfs(i + 1, j, grid), dfs(i, j + 1, grid));
        return dp[i][j];
    }
};