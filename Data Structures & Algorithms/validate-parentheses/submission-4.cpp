class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stack;

        for (const auto& c : s) {
            if (!stack.empty() && stack.top() == closeToOpen[c]) {
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
