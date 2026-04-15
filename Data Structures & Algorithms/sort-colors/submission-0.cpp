class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> c(3,0);

        for (int num : nums) {
            c[num]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < c[0]) {
                nums[i] = 0;
            }
            else if (i < c[0] + c[1]) {
                nums[i] = 1;
            }
            else {
                nums[i] = 2;
            }
        }
    }
};