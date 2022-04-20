class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++) {
            int last = ans.back();
            if(nums[i] > last) {
                ans.push_back(nums[i]);
            } else {
                auto it = lower_bound(ans.begin(),ans.end(),nums[i]);
                ans[it-ans.begin()] = nums[i];
            }
        }
        return ans.size();
    }
};