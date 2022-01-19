class Solution {
public:
    vector<string> ansV;
    void helper(string s,int open, int close, int n) {
        if(s.length()==2*n) {
            ansV.push_back(s);
            return;
        }
        if(open<n) {
            helper(s+'(',open+1,close,n);
        }
        if(close<open) {
            helper(s+')',open,close+1,n);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        if(n==0)return{};
        string ans="(";
        helper(ans,1,0,n);
        return ansV;
    }
};