class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        vector<int> results(digits.size()+1);
        results[0] = 1;
        return results;
    }
};
