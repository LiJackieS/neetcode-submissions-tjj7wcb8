class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int l = 0, lMax = height[l];
        int r = height.size() - 1, rMax = height[r];
        int sum = 0;

        while (l < r) {
            if (lMax < rMax) {
                l++;
                lMax = max(height[l],lMax);
                sum += lMax - height[l];
            }
            else {
                r--;
                rMax = max(height[r],rMax);
                sum += rMax - height[r];
            }
        }
        return sum;
    }
};
