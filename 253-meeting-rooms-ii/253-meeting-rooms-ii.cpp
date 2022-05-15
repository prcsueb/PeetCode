class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& inte) {
        int n = inte.size();
        if(n == 1) {
            return 1;
        }
        sort(inte.begin(),inte.end());
        priority_queue<int,vector<int>,greater<int>> pq; //min pq
        pq.push(inte[0][1]);
        int max_size = 1;
        for(int i=1;i<n;i++) {
            if(inte[i][0] < pq.top()) {
                pq.push(inte[i][1]);
                // max_size = max((int)pq.size(), max_size);
            } else {
                pq.pop();
                pq.push(inte[i][1]);
            }
        }
        return pq.size();
    }
};