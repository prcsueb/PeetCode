class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) {
            return {0};   
        }
        
        
        vector<vector<int>> graph(n);
        for(auto x : edges) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++) {
            indegree[edges[i][1]]++;
            indegree[edges[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(indegree[i]==1) {
                q.push(i);
            }
        }
        
        vector<int> res;
        while(!q.empty()) {
            int size=q.size();
            res.clear(); //last level is our answer till then store into ans and clear
            while(size>0) {
                size--;
                int front = q.front();
                q.pop();
                
                res.push_back(front);
                for(auto nei : graph[front]) {
                    indegree[nei]--;
                    if(indegree[nei]==1) {
                        q.push(nei);
                    }
                }
            }
        }
        
        return res;
    }
};