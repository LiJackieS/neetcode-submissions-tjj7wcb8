class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        int lmax = height[l];
        int rmax = height[r];

        while (l < r) {
            if (lmax < rmax) {
                l++;
                lmax = max(height[l], lmax);
                res += lmax - height[l];
            }
            else {
                r--;
                rmax = max(height[r], rmax);
                res += rmax - height[r];
            }
        }
        return res;
    }
};
