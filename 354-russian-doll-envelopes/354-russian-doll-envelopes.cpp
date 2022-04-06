class Solution {
public:
    static bool comparefn(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comparefn);
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