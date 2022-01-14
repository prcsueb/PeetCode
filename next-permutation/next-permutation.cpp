class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find idx1 where nums[i]<nums[i+1]
        int idx1=-1,idx2=-1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
                idx1=i;
                break;
            }
        }
        
        if(idx1==-1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        //find idx2 where nums[i]>nums[i+1]
        for(int i=n-1;i>=0;i--) {
            if(nums[i]>nums[idx1]) {
                idx2=i;
                break;
            }
        }
        
        //swap those
        swap(nums[idx1],nums[idx2]);
        
        
        //reverse (idx1+1,end)
        reverse(nums.begin()+idx1+1,nums.end());
        return;
    }
};