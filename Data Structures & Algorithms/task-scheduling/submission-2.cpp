class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        priority_queue<int> pq;
        queue<pair<int,int>> wq;
        vector<int> count(26, 0);

        for (char c : tasks) {
            count[c-'A']++;
        }

        for (int num : count) {
            if (num != 0) {
                pq.push(num);
            }
        }

        while (!pq.empty() || !wq.empty()) { // pq = {2}
            res++; // 4
            if (!wq.empty() && wq.front().first == res) { // wq = {{4,1}}
                pq.push(wq.front().second); // pq = {1}
                wq.pop(); // wq = {4,1}
            }
            if (!pq.empty()) {
                auto cur = pq.top(); // cur = 1
                cur--;
                if (cur == 0) {
                    pq.pop();
                }
                else { // pq = {}
                    pq.pop();
                    wq.push({res + n + 1, cur}); // wq = {(4,1)}
                }
            }
        }
        return res;
    }
};
