class Solution {
public:
    int rows;
    int cols;

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (dfs(row, col, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int r, int c, vector<vector<char>>& board, string word, int i) {
        if (i == word.size()) {
            return true;
        }
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[i] || board[r][c] == '#') {
            return false;
        }
        board[r][c] = '#';
        bool res = dfs(r + 1, c, board, word, i + 1) || dfs(r - 1, c, board, word, i + 1)
                    || dfs(r, c + 1, board, word, i + 1) || dfs (r, c - 1, board, word, i + 1);
        board[r][c] = word[i];

        return res;
    }
};
