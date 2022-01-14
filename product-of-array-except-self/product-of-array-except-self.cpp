class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //o(n) time
        //o(1) space - inplace
        int product=nums[nums.size()-1];
        vector<int> op(nums.size(),0);
        op[0]=nums[0];
        for(int i=1;i<nums.size();i++) {
            op[i]=nums[i]*op[i-1];
        }
        
        for(int i=nums.size()-1;i>=0;i--) {
            if(i==nums.size()-1) {
                op[nums.size()-1]=op[nums.size()-2];
            } else if(i == 0) {
                op[0]=product;
            } else {
                op[i]=product*op[i-1];
                cout << product << " , " << op[i-1] << endl;
                product=product*nums[i];
            }
        }
        return op;
    }
};