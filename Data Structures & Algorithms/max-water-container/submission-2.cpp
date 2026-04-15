class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int area = 0;
        int tempArea = 0;

        while (l < r) {
            if (heights.at(l) < heights.at(r)) {
                tempArea = (r - l) * (heights.at(l));
            }
            else {
                tempArea = (r - l) * (heights.at(r));
            }

            if (area < tempArea) {
                area = tempArea;
            }

            if (heights.at(l) < heights.at(r)) {
                l ++;
            }
            else {
                r --;
            }
            cout << tempArea << endl;
        }

        return area;
    }
};
