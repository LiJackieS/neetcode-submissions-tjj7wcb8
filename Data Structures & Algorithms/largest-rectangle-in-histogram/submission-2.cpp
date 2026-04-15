class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stack;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i]) {
                auto top = stack.top();
                int index = top.first;
                int height = top.second;

                maxArea = max(maxArea, height * (i-index));
                start = index;
                stack.pop();
            }
            stack.push({start, heights[i]});
        }
        while (!stack.empty()) {
            auto top = stack.top();
            int index = top.first;
            int height = top.second;

            maxArea = max(maxArea, (static_cast<int>(heights.size()) - index) * height);
            stack.pop(); 
        }
        return maxArea;
    }
};
