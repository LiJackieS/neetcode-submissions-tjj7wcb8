class FreqStack {
public:
    unordered_map<int, int> count;
    unordered_map<int, stack<int>> stacks;
    int maxCount;

    FreqStack() {
        maxCount = 0;
    }
    
    void push(int val) {
        int valueCount = ++count[val];
        if (valueCount > maxCount) {
            maxCount = valueCount;
            stacks[valueCount] = stack<int>();
        }
        stacks[valueCount].push(val);
    }
    
    int pop() {
        int res = stacks[maxCount].top();
        stacks[maxCount].pop();
        count[res]--;
        if (stacks[maxCount].empty()) {
            maxCount--;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */