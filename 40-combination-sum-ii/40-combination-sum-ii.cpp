class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& can, int tar, vector<int> &sub, int idx) {
        if(tar == 0) {
            ans.push_back(sub);
            return;
        }
        for(int i=idx;i<can.size();i++) {
            if(i > idx && can[i]==can[i-1]) {
                continue;
            }
            if(can[i] <= tar) {
                sub.push_back(can[i]);
                helper(can,tar-can[i],sub,i+1);
                sub.pop_back();
            } else {
                break;
            }
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        vector<int> sub;
        sort(can.begin(),can.end());
        helper(can,tar,sub,0);
        return ans;
    }
};