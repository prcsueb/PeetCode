class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> path(n,INT_MAX);
        path[src]=0;
        //in given example if k=0 then still we need to run bford atleast one time to get
        //smallest dist
        for(int i=0;i<k+1;i++) {
            vector<int> copy(path);
            for(int i=0;i<flights.size();i++) {
                int src = flights[i][0];
                int dest = flights[i][1];
                int wt = flights[i][2];
                if(path[src]==INT_MAX) {
                    continue;
                }
                copy[dest]=min(path[src]+wt,copy[dest]);
            }
            path=copy;
        }
        
        for(auto x : path) {
            cout << x << " , ";
        }
        
        return path[dst]==INT_MAX?-1:path[dst];
    }
};