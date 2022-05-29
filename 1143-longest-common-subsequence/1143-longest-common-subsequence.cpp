class Solution {
public:
    vector<vector<int>> dp;
    int helper(string &s1, string &s2, int i, int j) {
        if(i>=s1.length() || j>=s2.length()) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=helper(s1,s2,i+1,j+1) + 1;
        return dp[i][j]=max(helper(s1, s2, i+1, j), helper(s1, s2, i, j+1));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        dp.resize(size1+1, vector<int>(size2+1, -1));
        return helper(text1, text2, 0, 0);
    }
};