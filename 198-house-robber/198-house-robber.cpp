class Solution {
public:
    int helper(vector<int>& nums, int idx, vector<int> &dp) {
        if(idx >= nums.size()) {
            return 0;
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        int case1 = helper(nums, idx+1, dp);
        int case2 = helper(nums, idx+2, dp) + nums[idx];
        return dp[idx] = max(case1, case2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, 0, dp);
    }
};