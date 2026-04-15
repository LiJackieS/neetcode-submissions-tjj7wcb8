class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxP = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int temp = prices[r] - prices[l];
                maxP = max(maxP, temp);
            }
            else {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};
