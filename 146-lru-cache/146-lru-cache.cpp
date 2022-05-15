class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int key, int val) {
            this->key=key;
            this->val=val;
        }
    };
    
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    unordered_map<int, Node*> mp;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void remove(Node *node) {
        Node *prevNei = node->prev;
        Node *nextNei = node->next;
        prevNei->next = nextNei;
        nextNei->prev = prevNei;
        node->next = NULL;
        node->prev = NULL;      
    }
    
    void addFront(Node *node) {
        Node *headsNext = head->next;
        head->next=node;
        node->prev=head;
        node->next=headsNext;
        headsNext->prev=node;
    }
    
    void update(Node *node) {
        remove(node);
        addFront(node);
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        } else {
            update(mp[key]);
            return mp[key]->val;
        }
    }
    
    void put(int key, int value) {
        //if key already in map update it
        //else insert
        if(mp.find(key) != mp.end()) {
            Node *oldNode = mp[key];
            oldNode->val = value;
            update(oldNode);
        } else {
            Node *newNode = new Node(key,value);
            //check if capacity full
            if(cap == mp.size()) {
                mp.erase(tail->prev->key);
                remove(tail->prev);
                addFront(newNode);
                mp[key] = newNode;
            } else {
                mp[key] = newNode;
                addFront(newNode);
            }
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */