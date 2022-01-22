class Solution {
public:
    int helper(string s,int idx,vector<int> &dp) {
        if(s.length()==idx) {
            return dp[idx] = 1;
        }
        if(dp[idx]!=-1) {
            return dp[idx];
        }
        int ans=0;
        int firstNum = s[idx]-'0';
        if(firstNum==0) {
            return dp[idx] = 0;
        }
        ans+=helper(s,idx+1,dp);
        if(idx+1 < s.length()) {
            int secondNum = s[idx+1]-'0';
            int fullNum = firstNum * 10 + secondNum;
            if(fullNum <= 26) {
                ans+=helper(s,idx+2,dp);
            }
        }
        return dp[idx] = ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        return helper(s,0,dp);
    }
};