class Solution {
public:
    vector<vector<int>> dp;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();

        dp.resize(M, vector<int>(N, -1));
        return dfs(0, 0, obstacleGrid);
    }
    int dfs(int i, int j, vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();

        if (i >= M || j >= N || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (i == M - 1 && j == N - 1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        dp[i][j] = dfs(i + 1, j, obstacleGrid) + dfs(i, j + 1, obstacleGrid);
        return dp[i][j];
    }
};