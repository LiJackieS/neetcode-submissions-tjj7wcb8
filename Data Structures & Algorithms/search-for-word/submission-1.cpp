class Solution {
public:
    int row;
    int col;
    bool exist(vector<vector<char>>& board, string word) {
        col = board[0].size();
        row = board.size();

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (dfs(r, c, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;

    }
    bool dfs(int r, int c, int i, vector<vector<char>>& board, string& word) {
        if (i == word.size()) return true;

        if (r < 0 || c < 0 || r >= row || c >= col || word[i] != board[r][c]) return false;

        if (board[r][c] == '#') return false;
        
        board[r][c] = '#';

        bool res = dfs(r + 1, c, i + 1, board, word) || dfs(r - 1, c, i + 1, board, word)
                    || dfs(r, c + 1, i + 1, board, word) || dfs(r, c - 1, i + 1, board, word);
        board[r][c] = word[i];
        return res;
    }
};
