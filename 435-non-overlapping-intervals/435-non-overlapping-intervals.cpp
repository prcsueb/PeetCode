class Solution {
public:
    static bool compare(vector<int> &ele1, vector<int> &ele2) {
        return ele1[1] < ele2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        //logic is we count all intervals that are non overlapping and then (length of intervals - count) = overlapping
        int end=intervals[0][1];
        int counter=1;
        for(int i=0;i<intervals.size();i++) {
            if(end<=intervals[i][0]) {
                counter++;
                end=intervals[i][1];
            }
        }
        return intervals.size()-counter;
    }
};