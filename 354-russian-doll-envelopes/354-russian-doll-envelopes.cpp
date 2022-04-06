class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(), [](auto const &l, auto const &r) {
            if(l[0] == r[0]) {
                return l[1] > r[1];
            }
            return l[0] < r[0];
        });
        
        vector<int> dp;
        
        for(int i=0;i<n;i++) {
           auto itr = lower_bound(dp.begin(),dp.end(),intervals[i][1]);
            if(itr == dp.end()) {
                dp.push_back(intervals[i][1]);
            } else {
                *itr = intervals[i][1];
            }
        }
        return dp.size();
    }
};

// [[30,50],[12,2],[3,4],[12,15]]