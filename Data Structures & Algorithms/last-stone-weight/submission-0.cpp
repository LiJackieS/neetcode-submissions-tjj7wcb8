class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (const auto& s : stones) {
            maxHeap.push(s);
        }
        while (maxHeap.size() > 1) {
            auto first = maxHeap.top();
            maxHeap.pop();
            auto second = maxHeap.top();
            maxHeap.pop();
            if (second < first) {
                maxHeap.push(first - second);
            }
        }
        maxHeap.push(0);
        return maxHeap.top();
    }
};
