class MyCircularQueue {
public:
    vector<int> q;
    int l;
    int r;
    int size = 0;
    MyCircularQueue(int k) {
        l = 0;
        r = 0;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if (size == q.size()) {
            return false;
        }
        q[(r + q.size()) % q.size()] = value;
        r++;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        l++;
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return q[l % q.size()];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return q[(r - 1 + q.size()) % q.size()];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == q.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */