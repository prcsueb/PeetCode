class Solution {
public:
    void helper(int n,int r, vector<vector<int>> &ans, vector<int> &sub, int idx) {
        if(sub.size() == r) {
            ans.push_back(sub);
            return;
        }
        
        for(int i=idx;i<=n;i++) {
            sub.push_back(i);
            helper(n,r,ans,sub,i+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> sub;
        helper(n,k,ans,sub,1);
        return ans;
    }
};