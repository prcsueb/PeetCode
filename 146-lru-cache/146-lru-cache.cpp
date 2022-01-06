class LRUCache {
public:
    class Node {
        public:
        int key, value;
        Node *prev, *next;
        Node(int key, int val) {
            this->key = key;
            this->value = val;
        }
    };
    
    unordered_map<int, Node*> cache;
    int cap;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    
    void addFirst(Node *node) {
        node->next = head->next;
        node->prev=head;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Node *node) {
        Node *prevNei = node->prev;
        Node *nextNei = node->next;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev=node->next=NULL;
    }
    
    void moveToFront(Node *node) {
        removeNode(node);
        addFirst(node);
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            moveToFront(cache[key]);
            return cache[key]->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        //check if it's already in the map or not
        if(cache.find(key) == cache.end()) {
            //can't found key
            Node *newNode = new Node(key, value);
            if(cache.size() == cap) {
                Node *LRU_node = tail->prev;
                removeNode(LRU_node);
                cout << cache.size() << endl;
                cache.erase(cache.find(LRU_node->key));
            } 
            cache[key]=newNode;
            addFirst(newNode);
        } else {
            //found key
            cache[key]->value = value;
            moveToFront(cache[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */