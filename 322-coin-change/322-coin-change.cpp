class Solution {
    int dp[1000001]={0};
    
    int mincoin(vector<int>&coins,int amount)
    {
         if(amount == 0)
             return dp[amount] = 0;
        
        
        if(dp[amount]) return dp[amount];
        
        int mini = INT_MAX;
        
        for(int i=0;i<coins.size();i++)
        {   
            if(amount - coins[i] >=0)
                    mini = min(mini,mincoin(coins,amount - coins[i]));
            
        } 
        
        if(mini == INT_MAX) return dp[amount] = INT_MAX;
      
        
        return dp[amount] = mini + 1;
    }
    
public:
    
   
    int coinChange(vector<int>& coins, int amount) {
        
        int ans=mincoin(coins, amount);
        if(ans==INT_MAX) {
            return -1;
        }
        return ans;
    }
};