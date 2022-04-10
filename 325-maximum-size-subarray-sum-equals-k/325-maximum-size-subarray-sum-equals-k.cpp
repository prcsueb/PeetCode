class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
            if(mp.find(sum - k) != mp.end()) {
                ans = max(ans, i - mp[sum - k]);
            }
            
        }
        
        return ans;
    }
};