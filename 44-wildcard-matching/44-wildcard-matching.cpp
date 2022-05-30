class Solution {
public:
    string removeMultipleStars(string &p) {
        if(p.length()==0) return p;
        string ans="";
        ans += p[0];
        for(int i=1;i<p.length();i++) {
            if(ans.back() == '*' && p[i] == '*') {
                continue;
            } else {
                ans+=p[i];
            }
        }
        return ans;
    }
    bool helper(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        if(s.length()==i && p.length()==j) return dp[i][j]=true;
        if(i<s.length() && p.length()==j) return dp[i][j]=false;
        if(s.length()==i && j<p.length()) {
            if(j==p.length()-1 && p[j]=='*') {
                return dp[i][j]=true;
            }
            return dp[i][j]=false;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i] == p[j] || p[j]=='?') {
            return dp[i][j]=helper(s,p,i+1,j+1,dp);
        }
        if(p[j]=='*') {
            return dp[i][j]=helper(s,p,i,j+1,dp) || helper(s,p,i+1,j+1,dp) || helper(s,p,i+1,j,dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        if(s.length()==0 && p.length()==0) {
            return true;
        } 
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
        p=removeMultipleStars(p);
        cout << p << endl;
        return helper(s,p,0,0,dp);
    }
};