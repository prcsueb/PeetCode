//https://leetcode.com/problems/all-oone-data-structure/discuss/403466/Accepted-Java-solution-using-HashMap-and-Doubly-Linked-List
class AllOne {
public:
    class Node {
        public:
        int freq;
        unordered_set<string> keys;
        Node *prev = NULL;
        Node *next = NULL;
        unordered_set<string> ::iterator start = keys.begin();
        unordered_set<string> ::iterator end = keys.end();
        Node(int f) {
            freq = f;
        }
        Node(string key, int f) {
            freq = f;
            keys.insert(key);
        }
    };
    
    unordered_map<string, Node*> mp;
    Node *head;
    Node *tail;
    
    AllOne() {
        head = new Node(-1);
        tail = new Node(-1);
        head->next=tail;
        tail->prev=head;
    }
    
    void insertNext(Node *node, Node *newNode) {
        node->next->prev = newNode;
        newNode->next=node->next;
        newNode->prev=node;
        node->next=newNode;
    }
    
    void deleteNode(Node *node) {
        node->next->prev=node->prev;
        node->prev->next=node->next;
        node->prev=NULL;
        node->next=NULL;
    }
    
    void removeKey(Node *node, string key) {
        node->keys.erase(key);
        if(node->keys.size() == 0) {
            deleteNode(node);
        }
    }
    
    void inc(string key) {
        //if key is present in map or not
        if(mp.find(key)!=mp.end()) {
            Node *node = mp[key];
            if(node->next->freq == node->freq+1) {
                mp[key]=node->next;
                node->next->keys.insert(key);
            } else {
                Node *newNode = new Node(key, node->freq + 1);
                mp[key] = newNode;
                insertNext(node, newNode);
            }
            removeKey(node, key);
        } else {
            if(head->next->freq == 1) {
                head->next->keys.insert(key);
                mp[key]=head->next;
            } else {
                Node *newNode = new Node(key, 1);
                insertNext(head, newNode);
                mp[key]=newNode;
            }
        }
    }
    
    void dec(string key) {
        if(mp.find(key)==mp.end()) return;
        Node *node = mp[key];
        if(node->freq == 1) {
            mp.erase(key);
        }
        else if(node->prev->freq == node->freq-1) {
            node->prev->keys.insert(key);
            mp[key]=node->prev;
        } else {
            Node *newNode = new Node(key, node->freq-1);
            mp[key] = newNode;
            insertNext(node->prev, newNode);
        }
        removeKey(node, key);
    }
    
    string getMaxKey() {
        string ans = "";
        if(tail->prev->freq != -1) {
            ans = *tail->prev->keys.begin();
        }
        return ans;
    }
    
    string getMinKey() {
        string ans = "";
        if(head->next->freq != -1) {
            ans = *(head->next->keys.begin());
        }
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */