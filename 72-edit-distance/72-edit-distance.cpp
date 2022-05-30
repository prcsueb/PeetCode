class Solution {
public:
    int helper(string s, string t, int i, int j, vector<vector<int>> &dp) {
        //if both the strings are 0
        if(i==s.length() && j==t.length()) return dp[i][j]=0;
        //if s is not 0 and t is 0
        if(i<s.length() && j==t.length()) return dp[i][j]=s.length()-i;
        if(i==s.length() && j<t.length()) return dp[i][j]=t.length()-j;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) {
            return dp[i][j]=helper(s,t,i+1,j+1,dp);
        }
        return dp[i][j]=1+min(helper(s,t,i,j+1,dp), min(helper(s,t,i+1,j,dp), helper(s,t,i+1,j+1,dp)));
    }
    
    int minDistance(string s, string t) {
        vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));
        return helper(s,t,0,0,dp);
    }
};