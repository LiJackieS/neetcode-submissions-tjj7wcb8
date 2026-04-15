class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        stack<char> stack;

        for (char c : s) {
            if (!stack.empty()) {
                if (stack.top() == closeToOpen[c]) {
                    stack.pop();
                }
                else {
                    stack.push(c);
                }
            }
            else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
