struct Node {
    int key;
    int val;
    int freq;

    list<int>::iterator it;

    Node() {
        this->key = 0;
        this->val = 0;
        this->freq = 0;
    }

    Node(int key, int val, int freq) {
        this->key = key;
        this->val = val;
        this->freq = freq;
    }
};

class LFUCache {
private:
    unordered_map<int, Node> mp; // key -> Node
    map<int, list<int>> cache; // freq -> list of keys
    int capacity = 0;
    int cur_capacity = 0;
public:
    
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        

        cache[mp[key].freq].erase(mp[key].it);

        if (cache[mp[key].freq].empty()) {
            cache.erase(mp[key].freq);
        }

        mp[key].freq++;
        int freq = mp[key].freq;

        cache[freq].push_back(key);
        mp[key].it = prev(cache[freq].end());

        return mp[key].val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].val = value;
            cache[mp[key].freq].erase(mp[key].it);
            cache[mp[key].freq].push_back(key);
            mp[key].it = prev(cache[mp[key].freq].end());
        }
        else {
            if (cur_capacity >= capacity) {
                auto evict_list = cache.begin()->second;
                int evict_key = *evict_list.begin();
                Node evict_node = mp[evict_key];

                cache[evict_node.freq].erase(evict_node.it);
                if (cache[evict_node.freq].empty()) {
                    cache.erase(evict_node.freq);
                }
                
                mp.erase(evict_node.key);
                cur_capacity--;
            }
            Node node(key,value,1);
            mp[key] = node;
            cache[1].push_back(key);
            mp[key].it = prev(cache[1].end());
            cur_capacity++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */