class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int l = 0;
        for (int r = 0; r < prices.size(); r++) {
            if (prices[r] > prices[l]) {
                int profit = prices[r] - prices[l];
                res = max(profit, res);
            }
            else {
                l = r;
            }
        }
        return res;
    }
};
