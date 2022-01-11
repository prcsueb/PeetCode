class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) {
            return 1;
        }
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> pq;// min pq
        int ans=1;
        pq.push(intervals[0][1]);
        for(int i=1;i<n;i++) {
            if(intervals[i][0] < pq.top()) {
                pq.push(intervals[i][1]);
                ans = max(ans,(int)pq.size());//pq.size() return unsigned long so typecast into (int)
            } else {
                pq.pop();
                pq.push(intervals[i][1]);
            }
        }
        
        return ans;
    }
};