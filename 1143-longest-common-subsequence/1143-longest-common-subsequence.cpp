class Solution {
public:
    vector<vector<int>> dp;
    int helper(const string &s1, const string &s3, int i,int j) {
        if(i >= s1.length() || j >= s3.length()) {
            return dp[i][j] = 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if(s1[i] == s3[j]) {
            return dp[i][j] = helper(s1, s3, i+1, j+1) + 1;
        }
        
        return dp[i][j] = max(helper(s1, s3, i+1, j), helper(s1, s3, i, j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        dp.resize(n+1, vector<int> (m+1,-1));
        return helper(text1, text2, 0, 0);
    }
};