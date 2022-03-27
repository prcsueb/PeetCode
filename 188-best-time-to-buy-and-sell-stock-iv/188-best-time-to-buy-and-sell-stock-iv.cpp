class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        if(k==0) return 0;
        vector<vector<int>> dp(k+1, vector<int> (n, 0));
        
        for(int i=1;i<=k;i++) {
            int maxx = INT_MIN;
            for(int j=1;j<n;j++) {
                maxx = max(maxx, dp[i-1][j-1] - prices[j - 1]);
                dp[i][j] = max(maxx + prices[j], dp[i][j-1]);
            }
        }
        
        return dp[k][n-1];
    }
};