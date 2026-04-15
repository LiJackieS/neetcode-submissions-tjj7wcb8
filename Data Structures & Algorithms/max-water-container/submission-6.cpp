class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int temp = 0;

        int l = 0, r = heights.size() - 1;

        while (l < r) {
            temp = min(heights[l], heights[r]) * (r - l);
            if (heights[l] > heights[r]) {
                r -= 1;
            } 
            else {
                l += 1;
            }
            maxArea = max(temp, maxArea);
        }
        return maxArea;
    }
};
