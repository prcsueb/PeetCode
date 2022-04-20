class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),compare);
        
        int counter=1;
        int end=intervals[0][1];
        
        for(int i=0;i<n;i++) {
            if(end <= intervals[i][0]) {
                counter++;
                end = intervals[i][1];
            }
        }
        
        return n-counter;
    }
};