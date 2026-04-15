class Solution {
public:
    int climbStairs(int n) {
        // dp[i] = dp[i-1] + dp[i-2]

        int a = 1;
        int b = 2;
        if (n == 1) return 1;

        for (int i = 2; i < n; i++) {
            int temp = b;
            b += a;
            a = temp;
        }
        return b;
    }
};
