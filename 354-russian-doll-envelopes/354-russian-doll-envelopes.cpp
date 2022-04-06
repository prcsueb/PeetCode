class Solution {
public:
    static bool comparefn(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
            return a[1] > b[1]; //desc base on height becase if there is a case prevent calculating the envelope with the same width? For example [3, 1] [3, 2] [3, 3] will get 3, but [3, 3], [3, 2], [3, 1] will get 1
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