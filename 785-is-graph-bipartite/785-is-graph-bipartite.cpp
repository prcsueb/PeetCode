class Solution {
public:
    class Pair {
        public:
        int vertex;
        int level;
        Pair(int v, int l) {
            level=l;
            vertex=v;
        }
    };
    bool bfs(vector<vector<int>> &graph, int src, vector<int> &visited) {
        queue<Pair *> q;
        q.push(new Pair(src, 1));
        
        while(!q.empty()) {
            Pair *front = q.front();
            q.pop();
            if(visited[front->vertex] != -1) {
                if(visited[front->vertex] != front->level) {
                    return false;
                }
                continue;
            }
            visited[front->vertex] = front->level;
            for(auto x : graph[front->vertex]) {
                if(visited[x] == -1) {
                    if(front->level == 1) {
                        q.push(new Pair(x, 2));
                    } else {
                        q.push(new Pair(x, 1));
                    }
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size()+1, -1);
        bool ans = true;
        for(int i=0;i<graph.size();i++) {
            if(visited[i] == -1) {
                ans = ans && bfs(graph, i, visited);
                if(!ans) return false;
            }
        }
        
        return true;
    }
};