class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        backtrack(s, {}, 0, 0);
        return res;
    }
    void backtrack(string s, vector<string> cur, int l, int r) {
        if (r >= s.size()) {
            if (l == r) {
                res.push_back(cur);
            }
            return;
        }
        if (isPalindrome(s, l, r)) {
            cur.push_back(s.substr(l, r - l + 1));
            backtrack(s, cur, r + 1, r + 1);
            cur.pop_back();
        }
        backtrack(s, cur, l, r + 1);

    }
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
