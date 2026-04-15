class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int sum = 0;

        while (l < r) {
            if (rightMax < leftMax) {
                r--;
                rightMax = max(rightMax, height[r]);
                sum += rightMax - height[r];
            }
            else {
                l++;
                leftMax = max(leftMax, height[l]);
                sum += leftMax - height[l];
            }
        }
        return sum;
    }
};
