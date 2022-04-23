class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        map<int,int> mp;
        mp[0] = 1;
        int ans = 0;
        for(auto &x : nums) {
            sum += x;
            if(mp.find(sum-k) != mp.end()) {
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        
        return ans;
    }
};
