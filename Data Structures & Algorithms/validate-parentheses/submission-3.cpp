class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
            };
        for (const auto &c: s) {
            if (closeToOpen.find(c) != closeToOpen.end()) {
                if (stack.empty()) {
                    return false;
                }
                if (stack.top() != closeToOpen[c]) {
                    return false;
                }
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
