class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        vector<int> count(26,0);
        for (int task : tasks) {
            count[task-'A']++;
        }
        priority_queue<int> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                maxHeap.push(count[i]);
            }
        }
        queue<pair<int,int>> queue;
        
        while (!queue.empty() || !maxHeap.empty()) {
            res++;
            if (maxHeap.empty()) {
                res = queue.front().second;
            }
            else {
                int cur = maxHeap.top() - 1;
                maxHeap.pop();
                if (cur > 0) {
                    queue.push({cur, res + n});
                }
            }
            if (!queue.empty() && queue.front().second == res) {
                maxHeap.push(queue.front().first);
                queue.pop();
            }
        }
        return res;
    }
};
