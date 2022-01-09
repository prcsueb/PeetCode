class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp; //{prefixsum%k , idx}
        int n =nums.size();
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            if(mp.find(sum%k)!=mp.end()) {
                //checking subarray size is >=2 only then it's valid
                if(i - mp[sum%k] >= 2) {
                    return true;
                }
            }
            else {
                mp[sum%k]=i;
            }
            
        }
        
        return false;
    }
};