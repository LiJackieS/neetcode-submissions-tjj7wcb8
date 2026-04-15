class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> memo;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        memo.resize(rows, vector<int>(cols, -1));
        int res = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                res = max(res, dfs(r, c, INT_MIN, matrix));
            }
        }
        return res;
    }

    int dfs(int r, int c, int prevVal, vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols || matrix[r][c] <= prevVal) {
            return 0;
        }
        if (memo[r][c] != -1) {
            return memo[r][c];
        }
        int res = 1;
        for (const auto& dir : dirs) {
            res = max(res, 1 + dfs(r + dir[0], c + dir[1], matrix[r][c], matrix));
        }
        memo[r][c] = res;

        return res;
    }
};
