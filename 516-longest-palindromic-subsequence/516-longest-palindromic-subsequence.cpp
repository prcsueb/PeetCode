class Solution {
public:
    int helper(string &s, int i, int j, vector<vector<int>> &dp) {
        if(i == j) {
            return dp[i][j] = 1;
        } else if(i > j) {
            return dp[i][j] = 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i] == s[j]) {
            return dp[i][j] = 2 + helper(s, i + 1, j - 1, dp);
        } 
    
        return dp[i][j] = max(helper(s, i+1, j, dp), helper(s, i, j-1, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(s, 0, n-1, dp);
    }  
};