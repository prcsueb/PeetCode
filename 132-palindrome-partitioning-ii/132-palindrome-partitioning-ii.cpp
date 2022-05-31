class Solution {
public:
    void longestPalindrome(string &s, vector<vector<int>> &pdp) {
        int n = s.size();
        for(int d=0;d<pdp.size();d++) {
            for(int i=0,j=d;j<pdp[0].size();i++,j++) {
                if(d == 0) {
                    pdp[i][j] = 1;
                } else if(d == 1 && s[i] == s[j]) {
                    pdp[i][j] = 1;
                } else {
                    if(s[i] == s[j] && pdp[i+1][j-1] != 0) {
                        pdp[i][j] = 1;
                    } else {
                        pdp[i][j] = 0;
                    }
                }
            }
        }
    }
    int helper(string &s, int si, int ei, vector<vector<int>> &pdp, vector<int> &dp) {
        if(pdp[si][ei] != 0) {
            return dp[si] = 0;
        }
        if(dp[si] != -1) return dp[si];
        int minAns = (int)(1e8);
        for(int cut=si;cut<=ei;cut++) {
            if(pdp[si][cut] != 0) {
                minAns = min(minAns, helper(s, cut+1, ei, pdp, dp) + 1);
            }
        }
        return dp[si] = minAns;
    }
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> pdp(n, vector<int>(n, 0));
        vector<int> dp(n+1, -1);
        longestPalindrome(s, pdp);
        return helper(s, 0, n-1, pdp, dp);
    }
};