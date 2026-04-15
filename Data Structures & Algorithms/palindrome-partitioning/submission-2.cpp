class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        backtrack(0, 0, s , {});
        return res;
    }
    void backtrack(int l, int r, string s, vector<string> cur) {
        if (r >= s.size()) {
            if (l == r) {
                res.push_back(cur);
            }
            return;
        }
        if (isPalindrome(l, r, s)) {
            cur.push_back(s.substr(l, r-l+1));
            backtrack(r + 1, r + 1, s, cur);
            cur.pop_back();
        }
        backtrack(l, r + 1, s, cur);
    }
    bool isPalindrome(int l, int r, string s) {
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
