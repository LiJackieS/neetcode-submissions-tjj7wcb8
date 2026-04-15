class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int,int>> stack; // temp, index

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first) {
                auto cur = stack.top();
                res[cur.second] = i - cur.second;
                stack.pop();
            }
            stack.push({t,i});
        }
        return res;
    }
};
