struct Node {
    Node* next;
    Node* prev;
    int key;
    int value;

    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    Node* right;
    Node* left;
    unordered_map<int, Node*> cache; // cache : {key, Node}

    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        next->prev = prev;
        prev->next = next;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);
        if (cache.size() > capacity) {
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }
    }
};
