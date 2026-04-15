class Solution {
public:
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    unordered_set<int> col;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur(n, string(n, '.'));
        backtrack(n, cur, 0);
        return res;
    }

    void backtrack(int n, vector<string>& cur, int r) {
        if (r == n) {
            res.push_back(cur);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (negDiag.count(r - c) || posDiag.count(r + c) || col.count(c)) {
                continue;
            }
            cur[r][c] = 'Q';

            posDiag.insert(r + c);
            negDiag.insert(r - c);
            col.insert(c);

            backtrack(n, cur, r + 1);

            posDiag.erase(r + c);
            negDiag.erase(r - c);
            col.erase(c);
            cur[r][c] = '.';
        }
    }
};
