class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        if(k==0) return 0;
        vector<vector<int>> dp(k+1, vector<int> (n, 0));
        
        for(int t=1;t<=k;t++) {
            for(int d=1;d<n;d++) {
                int maxx = dp[t][d-1];
                for(int prevday = 0; prevday < d; prevday++) {
                    int pastDayTm1 = dp[t-1][prevday];
                    int tthproft = prices[d] - prices[prevday];
                    maxx = max(maxx, pastDayTm1+tthproft);
                }
                dp[t][d] = maxx;
            }
        }
        
        return dp[k][n-1];
    }
};