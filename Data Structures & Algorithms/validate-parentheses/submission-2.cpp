class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        stack<char> open;

        for (const auto& c : s) {
            if (map.find(c) != map.end()) {
                if (open.empty()) {
                    return false;
                }
                if (open.top() != map[c]) {
                    return false;
                }
                open.pop();
            }
            else {
                open.push(c);
            }
        }
        return open.empty();
    }
};
