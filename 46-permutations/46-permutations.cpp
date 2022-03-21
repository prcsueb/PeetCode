class Solution {
public:
    void helper(vector<int>& nums, int first, vector<vector<int>> &ans) {
        if(first == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=first;i<nums.size();i++) {
            swap(nums[first], nums[i]);
            helper(nums, first+1, ans);
            swap(nums[first], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int first = 0;
        helper(nums, first, ans);
        return ans;
    }
};