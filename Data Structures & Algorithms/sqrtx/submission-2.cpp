class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int res = 0;

        while (l <= r) {
            int m = (l + r) / 2;
            long long m2 = (long long) m * m;

            if (m2 == x) {
                return m;
            }
            else if (m2 > x) {
                r = m - 1;
            }
            else {
                l = m + 1;
                res = m;
            }

        }

        return res;
    }
};