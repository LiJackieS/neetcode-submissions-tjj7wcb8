class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int cnt_a = 0;
        int cnt_b = 0;

        for (int num : nums) {
            if (a == num) {
                cnt_a++;
            }
            else if (b == num) {
                cnt_b++;
            }
            else if (cnt_a == 0) {
                a = num;
                cnt_a = 1;
            }
            else if (cnt_b == 0) {
                b = num;
                cnt_b = 1;
            }
            else {
                cnt_a--;
                cnt_b--;
            }
        }

        cnt_a = 0;
        cnt_b = 0;

        for (auto num : nums) {
            if (num == a) {
                cnt_a++;
            }
            else if (num == b) {
                cnt_b++;
            }
        }
        vector<int> res;

        if (cnt_a > nums.size() / 3) {
            res.push_back(a);
        }
        if (cnt_b > nums.size() / 3) {
            res.push_back(b);
        }
        return res;
    }
};