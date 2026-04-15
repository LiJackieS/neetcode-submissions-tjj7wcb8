class Solution {
public:
    void backtrack(int open, int close, int n, vector<string>& result, string& stack) {
        if (open == close && open == n) {
            result.push_back(stack);
            return;
        }
        if (open < n) {
            stack.push_back('(');
            backtrack(open + 1, close, n, result, stack);
            stack.pop_back();
        }
        if (close < open) {
            stack.push_back(')');
            backtrack(open, close + 1, n, result, stack);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string stack;
        backtrack(0, 0, n, result, stack);
        return result;
    }
};
