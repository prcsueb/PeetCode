class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int skip = 0;
        int prevSkip;
        int took = nums[0];
        for(int i=1;i<n;i++) {
            prevSkip = skip;
            skip = max(skip, took);
            took = nums[i] + prevSkip;
        }
        return max(skip, took);
    }
};