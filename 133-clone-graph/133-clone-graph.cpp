/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        
        Node *copyNode = new Node(node->val, {});
        mp[node]=copyNode;
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()) {
            Node *front = q.front();
            q.pop();
            for(Node *nei : front->neighbors) {
                if(mp.find(nei) == mp.end()) {
                    Node *cloneNode = new Node(nei->val, {});
                    mp[nei]=cloneNode;
                    q.push(nei);
                }
                mp[front]->neighbors.push_back(mp[nei]);
            }
        }
        
        return copyNode;
    }
};