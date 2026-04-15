class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int res = 0;
        for (int r = 0; r < prices.size(); r++) {
            int temp = prices[r] - prices[l];
            res = max(temp, res);
            if (prices[l] > prices[r]) {
                l = r;
            }
        }
        return res;
    }
};
