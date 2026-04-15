class Solution {
public:
    vector<int> memo;

    int minCostClimbingStairs(vector<int>& cost) {
        memo.resize(cost.size(), -1);
        return min(trip_cost(cost, 0), trip_cost(cost, 1));
    }

    int trip_cost(vector<int>& cost, int i) {
        if (i >= cost.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }

        memo[i] = cost[i] + min(trip_cost(cost, i + 1), trip_cost(cost, i + 2));

        return memo[i];
    }
};
