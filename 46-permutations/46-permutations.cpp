class Solution {
public:
    int zeroCounter=0;
    void permutations(vector<int>& nums, vector<vector<int>> &ans, vector<int> &one, int counter) {
        if(counter==nums.size()) {
            ans.push_back(one);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i] >= -10) {
                int val = nums[i];
                one.push_back(nums[i]);
                nums[i]=-11;
                counter++;
                permutations(nums,ans,one,counter);
                nums[i]=val;
                counter--;
                one.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> one;
        permutations(nums, ans, one, 0);
        return ans;
    }
};