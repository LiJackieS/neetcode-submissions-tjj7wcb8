class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = sumOfSquares(n);
        while (fast != 1) {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
            if (slow == fast) {
                return false;
            }
        }
        return true;
    }
    int sumOfSquares(int n) {
        int sum = 0;
        while (n != 0) {
            int remainder = n % 10;
            sum += remainder * remainder;
            n /= 10;
        }
        return sum;
    }
};
