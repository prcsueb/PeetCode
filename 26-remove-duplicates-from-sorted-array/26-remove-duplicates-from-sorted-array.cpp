class Solution {
public:
    
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int idx=0;//idx represents last unique element
        for(int j=0;j<nums.size();j++) {
            if(nums[idx]!=nums[j]) {
                nums[idx+1]=nums[j];
                idx++;
            }
        }
        //there are idx+1 unique elements
        return idx+1;
    }
};