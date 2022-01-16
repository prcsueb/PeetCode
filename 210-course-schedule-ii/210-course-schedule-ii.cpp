class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> graph(numCourses);
        for(auto x : prerequisites) {
            graph[x[0]].push_back(x[1]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++) {
            indegree[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        
        if(q.size()==0)return {};
        int count=0;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            count++;
            ans.push_back(front);
            for(auto nei : graph[front]) {
                indegree[nei]--;
                if(indegree[nei]==0) {
                    q.push(nei);
                }
            }
        }
        
        if(count==numCourses) {
            reverse(ans.begin(),ans.end());
            return ans;
        }
        
        return {};
    }
};