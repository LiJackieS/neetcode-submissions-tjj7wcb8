class Solution {
public:
    string multiply(string num1, string num2) {
        long long prod = (convert_to_int(num1) * convert_to_int(num2));
        return to_string(prod);
    }

    long long convert_to_int(string s) {
        long long res = 0;
        long long base = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            res += base * (s[i] - '0');
            base *= 10;
        }
        return res;
    }
};
