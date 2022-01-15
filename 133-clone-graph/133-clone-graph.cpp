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
    void dfs(Node* node, Node *copyNode, map<int,Node*> &visited) {
        visited[copyNode->val]=copyNode;
        for(auto x : node->neighbors) {
            if(visited[x->val]==NULL) {
                Node *newNode = new Node(x->val);
                copyNode->neighbors.push_back(newNode);
                dfs(x,newNode,visited);
            } else {
                copyNode->neighbors.push_back(visited[x->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)return node;
        Node *copyNode = new Node(node->val);
        map<int,Node*> visited;
        dfs(node,copyNode,visited);
        return copyNode;
    }
};