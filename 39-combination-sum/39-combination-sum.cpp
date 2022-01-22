class Solution {
public:
    void helper(vector<int>& can, int target, int idx, vector<int>& sub,vector<vector<int>> &ans) {
        if(can.size() == idx) {
            if(target==0) {
                ans.push_back(sub);
            }
            return;
        }    
        if(can[idx] <= target) {
            sub.push_back(can[idx]);
            helper(can,target-can[idx],idx,sub,ans);
            sub.pop_back();
        }
        helper(can,target,idx+1,sub,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        vector<vector<int>> ans;
        helper(candidates,target,0,sub,ans);
        return ans;
    }
};