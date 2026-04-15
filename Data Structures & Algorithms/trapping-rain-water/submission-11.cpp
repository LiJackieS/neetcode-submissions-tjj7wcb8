class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, lMax = height[l];
        int r = height.size() - 1, rMax = height[r];
        int res = 0;
        while (l < r) {
            if (lMax > rMax) {
                r--;
                rMax = max(height[r], rMax);
                res += rMax - height[r];
            }
            else {
                l++;
                lMax = max(height[l], lMax);
                res += lMax - height[l];
            }
        }
        return res;
    }
};
