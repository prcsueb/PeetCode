class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp; //{prefixsum%k,index}
        int sum=0;
        mp[0]=-1;
        //(sum1-sum2)%k==0.
        //sum1%k=sum2%k return true and size of subarray is >= 2
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if(mp.find(sum%k)!=mp.end()) {
                if(i-mp[sum%k]>=2) {
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