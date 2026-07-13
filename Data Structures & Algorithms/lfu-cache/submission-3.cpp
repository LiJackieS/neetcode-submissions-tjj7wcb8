struct Node {
    int key;
    int val;
    int freq;
    list<int>::iterator it;

    Node() : key(0), val(0), freq(0) {}
    Node(int key, int val, int freq) : key(key), val(val), freq(freq) {}
};

class LFUCache {
private:
    unordered_map<int, Node> mp; // key -> Node
    map<int, list<int>> cache; // freq -> lru : key
    int capacity;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    void update(int key, int old_freq) {
        Node& node = mp[key];
        cache[old_freq].erase(node.it);

        if (cache[old_freq].empty()) {
            cache.erase(old_freq);
        }

        cache[node.freq].push_back(key);
        node.it = prev(cache[node.freq].end());
    }

    void evict() {
        auto bucket = cache.begin();
        int key = bucket->second.front();
        
        bucket->second.pop_front();
        if (bucket->second.empty()) {
            cache.erase(bucket);
        }
        mp.erase(key);
    }
    
    int get(int key) {
        if (!mp.count(key)) {
            return -1;
        }
        int old_freq = mp[key].freq;
        mp[key].freq++;

        update(key, old_freq);

        return mp[key].val;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            int old_freq = mp[key].freq;
            mp[key].freq++;
            mp[key].val = value;
            update(key, old_freq);
        }
        else {
            if (mp.size() == capacity) {
                evict();
            }
            Node node = Node(key, value, 1);

            cache[1].push_back(key);
            node.it = prev(cache[1].end());
            mp[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */