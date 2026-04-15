class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int area = 0;
        while (l < r) {
            int temp_area = min(heights[l],heights[r]) * (r-l);
            area = max(temp_area, area);
            if (heights[l] > heights[r]) {
                r--;
            }
            else {
                l++;
            }
        }
        return area;
    }
};
