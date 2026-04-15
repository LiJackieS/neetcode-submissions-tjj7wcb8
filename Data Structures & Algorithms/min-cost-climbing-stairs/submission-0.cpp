class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> table(cost.size() + 1);

        for (int i = 2; i <= cost.size(); i++) {
            table[i] = min(table[i-1] + cost[i-1], table[i-2] + cost[i-2]);
        }
        return table.back();
    }
};
