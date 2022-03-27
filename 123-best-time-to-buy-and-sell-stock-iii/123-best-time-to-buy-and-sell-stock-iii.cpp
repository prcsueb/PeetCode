class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        vector<int> dp(n, -1);
        
        int minVal = prices[0];
        for(int i=1;i<n;i++) {
            minVal = min(minVal, prices[i]);
            dp[i] = max(prices[i]-minVal, dp[i-1]);
        }
        
        int maxVal = INT_MIN;
        int max_profit = INT_MIN;
        for(int i=n-1;i>=0;i--) {
            maxVal = max(maxVal, prices[i]);
            int todays_profit = maxVal - prices[i];
            max_profit = max(max_profit, dp[i] + todays_profit);
        }
        
        return max_profit;
    }
};