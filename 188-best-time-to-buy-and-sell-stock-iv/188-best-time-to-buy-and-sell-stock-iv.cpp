class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        if(k==0) return 0;
        vector<vector<int>> dp(k+1, vector<int> (n, 0));
        
        for(int i=1;i<=k;i++) {
            for(int j=1;j<n;j++) {
                int maxVal = dp[i][j-1];
                for(int k=0;k<j;k++) {
                    dp[i][j] = max(maxVal, dp[i-1][k] + (prices[j] - prices[k]));
                    maxVal = max(maxVal, dp[i][j]);
                }
            }
            cout << "\n";
        }
        
        return dp[k][n-1];
    }
};