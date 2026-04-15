class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        backtrack(n, k, cur, 1);
        return res;
    }
    
    void backtrack(int n, int k, vector<int>& cur, int i) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        for (int j = i; j <= n; j++) {
            cur.push_back(j);
            backtrack(n, k, cur, j + 1);
            cur.pop_back();
        }
    }
};