class Solution {
public:
    int helper(vector<int>& nums, int si, int ei, vector<vector<int>> &dp) {
        if(si > ei) return 0;
        if(dp[si][ei] != -1) return dp[si][ei];
        int lele = si == 0 ? 1 : nums[si-1];
        int rele = ei == nums.size()-1 ? 1 : nums[ei+1];
        int maxAns = 0;
        for(int cut=si;cut<=ei;cut++) {
            int leftCall = helper(nums, si, cut-1, dp);
            int rightCall = helper(nums, cut+1, ei, dp);
            int ans = leftCall + rightCall + nums[cut] * lele * rele;
            maxAns = max(ans, maxAns);
        }
        return dp[si][ei] = maxAns;
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return helper(nums, 0, nums.size()-1, dp);
    }
};