class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i=0;i<coins.size();i++) {
            for(int j=coins[i];j<dp.size();j++) {
                dp[j] += (dp[j - coins[i]]);
            }
        }
        return dp[amount];
    }
};