class Solution {
public:
    vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0, 1}, {0,-1}};
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if ((board[i][j] == 'O') && (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1)) {
                    bfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void bfs(vector<vector<char>>& board, int r, int c) {
        queue<pair<int,int>> q;
        int n = board.size();
        int m = board[0].size();
        q.push({r,c});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            board[r][c] = 'S';

            for (const auto& dir : directions) {
                int r = dir.first + row;
                int c = dir.second + col;

                if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O') {
                    board[r][c] = 'S';
                    q.push({r,c});
                }
            }
        }
    }
};
