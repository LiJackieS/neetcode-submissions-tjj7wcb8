class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (iswalnum(s.at(l)) == false) {
                l ++;
                continue;
            }
            if (iswalnum(s.at(r)) == false) {
                r --;
                continue;
            }
            if (tolower(s.at(l)) != tolower(s.at(r))) {
                return false;
            }
            l ++;
            r --;
        }
        return true;
    }
};
