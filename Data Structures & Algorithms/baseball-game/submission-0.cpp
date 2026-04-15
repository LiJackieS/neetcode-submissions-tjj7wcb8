class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int first = stack.top();
                stack.pop();
                int second = stack.top();
                stack.push(first);
                stack.push(first + second);
            }
            else if (operations[i] == "C") {
                stack.pop();
            }
            else if (operations[i] == "D") {
                stack.push(stack.top() * 2);
            }
            else {
                stack.push(stoi(operations[i]));
            }
        }
        int res = 0;

        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        return res;
    }
};