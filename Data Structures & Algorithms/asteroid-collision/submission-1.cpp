class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (int& a : asteroids) {
            while (!res.empty() && a < 0 && res.back() > 0) {
                int diff = a + res.back();
                if (diff < 0) {
                    res.pop_back();
                }
                else if (diff == 0) {
                    res.pop_back();
                    a=0;
                }
                else {
                    a=0;
                }
            }
            if (a != 0) {
                res.push_back(a);
            }
        }
        return res;
    }
};