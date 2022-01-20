class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currBst = 0;
        int overallBst = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            currBst+=nums[i];
            if(currBst > overallBst) {
                overallBst = currBst;
            }
            if(currBst < 0) {
                currBst = 0;
            }
        }
        return overallBst;
    }
};