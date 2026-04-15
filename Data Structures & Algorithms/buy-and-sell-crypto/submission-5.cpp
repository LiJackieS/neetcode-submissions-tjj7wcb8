class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int res = 0;
        for (int r = 0; r < prices.size(); r++) {
            if (prices[r] > prices[l]) {
                int temp = prices[r] - prices[l];
                res = max(temp, res);
            }
            else {
                l = r;
            }
        }
        return res;
    }
};
