class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        // We want to select all available tasks at a given time and work on the ones with the shortest processing time first. We have to keep track of an internal time variable.
        // We should first sort via time 
        for (int i = 0; i < tasks.size(); ++i) {
            tasks[i].push_back(i);
        }
        std::sort(tasks.begin(), tasks.end(), 
            [&](auto a, auto b) {
                return a[0] < b[0];
            });

        int time = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        for (int i = 0; i < tasks.size(); ++i) {
            auto task = tasks[i];
            int enqueTime = task[0];
            int processingTime = task[1];
            int index = task[2];

            while (!pq.empty() && time < enqueTime) {
                auto top = pq.top();
                res.push_back(top.second);
                time += top.first;
                pq.pop();
            }
            if (time < enqueTime) {
                time = enqueTime;
            }
            pq.push({processingTime, index});
        }
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};