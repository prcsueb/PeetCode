class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>> &dp) {
        if(i == nums1.size() || j == nums2.size()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int counter = 0;
        int left = 0;
        int right = 0;
        if(nums1[i] == nums2[j]) {
            counter = helper(nums1, nums2, i+1, j+1, dp) + 1;
        } else {
            left = helper(nums1, nums2, i+1, j, dp);
            right = helper(nums1, nums2, i, j+1, dp);
            counter += max(left, right);
        }
        return dp[i][j] = counter;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int> (nums2.size(), -1));
        return helper(nums1, nums2, 0, 0, dp);
    }
};