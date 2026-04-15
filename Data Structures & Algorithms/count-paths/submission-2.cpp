class Solution {
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n,-1));
        dp[m-1][n-1] = 1;
        return dfs(m, n, 0, 0);
    }
    int dfs(int m, int n, int i, int j) {
        if (i >= m || j >= n) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        dp[i][j] = dfs(m,n, i + 1, j) + dfs(m,n, i, j + 1);
        return dp[i][j];
    }
};
