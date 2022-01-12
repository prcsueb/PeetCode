class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        int j=-1;
        int i=-1;
        int sum=0;
        while(i<n-1) {
            while(i<n-1 && sum <= target) {
                ++i;
                sum+=nums[i];
                if(sum>=target) {
                    ans=min(ans,i-j);
                    cout << sum << endl;
                    break;
                }
            }
            // break;
            while(j<i) {
                ++j;
                sum-=nums[j];
                if(sum >= target) {
                    ans=min(ans,i-j);
                } else {
                    break;
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};