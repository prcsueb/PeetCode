class Solution {
public:
    bool canTraval(vector<int>& days, int cday) {
        for(int i=0;i<days.size();i++) {
            if(days[i]==cday) return true;
        }
        return false;
    }
    int helper(vector<int>& days, vector<int>& costs, int cday, vector<int> &dp) {
        if(cday > days[days.size()-1]) {
            return 0;
        }
        if(dp[cday]!=-1) return dp[cday];
        int ans = INT_MAX;
        if(canTraval(days, cday)) {
            ans = min(ans, helper(days, costs, cday+1, dp) + costs[0]);
            ans = min(ans, helper(days, costs, cday+7, dp) + costs[1]);
            ans = min(ans, helper(days, costs, cday+30, dp) + costs[2]);
        } else {
            ans = min(ans, helper(days, costs, cday+1, dp));
        }
        
        return dp[cday]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days[days.size()-1]+1, -1);
        return helper(days, costs, days[0], dp);
    }
};