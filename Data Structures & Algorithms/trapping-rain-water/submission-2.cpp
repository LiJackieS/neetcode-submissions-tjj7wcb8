class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty() == true) {
            return 0;
        }

        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        int leftMax = height.at(l);
        int rightMax = height.at(r);

        while (l < r) {
            if (leftMax < rightMax) {
                l ++;
                if (leftMax < height.at(l)) {
                    leftMax = height.at(l);
                }
                res += leftMax - height.at(l);
            }
            else {
                r --;
                if (rightMax < height.at(r)) {
                    rightMax = height.at(r);
                }
                res += rightMax - height.at(r);
            }
        }

        return res;
    }
};
