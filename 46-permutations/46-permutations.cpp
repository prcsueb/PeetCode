class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int>& nums, int idx) {
        if(idx==nums.size()) {
            ans.push_back(nums);
        }
        for(int i=idx;i<nums.size();i++) {
            swap(nums[i],nums[idx]);
            helper(ans,nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(ans,nums,0);
        return ans;
    }
};