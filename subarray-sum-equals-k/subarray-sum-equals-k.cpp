class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;//{sum,index}
        mp[0]=1;
        int sum = 0;int ans=0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};