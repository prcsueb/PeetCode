class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;i++) {
            int maxx=0;
            for(int j=i-1;j>=0;j--) {
                if(nums[i] > nums[j]) {
                    maxx = max(maxx, dp[j]);
                }
            }
            dp[i] = maxx + 1;
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};