struct Node {
    Node* next;
    Node* prev;;
    int value;
    int key;

    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr){}
};

class LRUCache {
private:
    int capacity;
    Node* left;
    Node* right;
    unordered_map<int, Node*> cache;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        right->prev = node;
        node->next = right;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        right = new Node(0, 0);
        left = new Node(0, 0);
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
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
