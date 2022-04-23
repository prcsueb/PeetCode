class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans=0;
        for(int d=0; d<n; d++) {
            for(int i=0,j=d;i<n&&j<n;i++,j++) {
                if(d == 0) {
                    dp[i][j] = true;
                } else if(d == 1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i+1][j-1] == true ? true : false;
                }
                if(dp[i][j] == true) {
                    ans++;
                }
            }
        }
        return ans;
    }
};