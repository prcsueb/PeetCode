class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 1) {
            return false;
        }
        vector<int> prefixSum(len);
        map<int,int> mp;// {sum%k and index}
        mp[0] = -1;
        
        int sum = 0;
        for(int i=0;i<len;i++) {
            sum += nums[i];
            if(mp.find(sum % k) != mp.end()) {
                if(i - mp[sum % k] >= 2) {
                    return true;
                }
            } else {
                mp[sum%k] = i;
            }
        }
        return false;
    }
};