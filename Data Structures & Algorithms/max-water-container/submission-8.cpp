class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            if (heights[l] > heights[r]) {
                res = max(res, heights[r] * (r - l));
                r--;
            }
            else {
                res = max(res, heights[l] * (r - l));
                l++;
            }
        }
        return res;
    }
};
