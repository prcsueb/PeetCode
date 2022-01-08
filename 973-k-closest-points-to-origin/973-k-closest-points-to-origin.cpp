class Solution {
public:
    typedef pair<int, int> pair;
    // priority_queue<pi, vector<pi>, greater<pi> > pq;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        multimap<int,int> mp; //nlogn for inserting all
        for(int i=0;i<points.size();i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x+y*y;
            mp.insert({dist,i});
        }
        vector<vector<int>> ans;
        for(auto it=mp.begin();it!=mp.end()&&k>0;it++) {
            ans.push_back(points[it->second]);
            k--;
        }
        
        
        return ans;
    }
};