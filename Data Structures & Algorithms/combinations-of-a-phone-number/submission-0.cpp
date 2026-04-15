class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res;
        }
        backtrack(digits, "", 0);
        return res;
    }
    void backtrack(string digits, string cur, int i) {
        if (i >= digits.size()) {
            res.push_back(cur);
            return;
        }
        string characters = digitToChar[digits[i] - '0'];
        for (char c : characters) {
            backtrack(digits, cur + c, i + 1);
        }
    }
};
