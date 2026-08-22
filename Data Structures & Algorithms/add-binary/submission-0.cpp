class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size()) {
            swap(a,b);
        } // b is the larger one
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        int carry = 0;
        std::string res;

        for (int i = 0; i < a.size(); ++i) {
            char sum = (a[i] - '0') + b[i];

            if (carry == 1) {
                sum++;
                carry = 0;
            }
            if (sum == '3') {
                sum = '1';
                carry = 1;
            }
            else if (sum == '2') {
                sum = '0';
                carry = 1;
            }
            res.push_back(sum);
        }

        for (int i = a.size(); i < b.size(); ++i) {
            char sum = b[i];
            if (carry == 1) {
                sum++;
                carry = 0;
            }

            if (sum == '2') {
                carry = 1;
                sum = '0';
            }
            res += sum;
        }
        if (carry == 1) {
            res += '1';
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};