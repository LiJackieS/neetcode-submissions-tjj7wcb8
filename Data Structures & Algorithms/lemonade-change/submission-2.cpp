class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
                continue;
            }
            if (bill == 10) {
                ten++;
                if (five <= 0) {
                    return false;
                }
                five--;
            }
            if (bill == 20) {
                twenty++;
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                    continue;
                }
                if (five > 2) {
                    five -= 3;
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};