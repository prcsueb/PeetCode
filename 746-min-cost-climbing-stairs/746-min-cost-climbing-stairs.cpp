class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        vector<int> dp(N, 0);
        for(int n=0;n<N;n++) {
            if(n <= 1) {
                dp[n] = cost[n];
                continue;
            }
            dp[n] = min(dp[n-1], dp[n-2]) + cost[n];
        }
        return min(dp[N-1], dp[N-2]);
    }
};