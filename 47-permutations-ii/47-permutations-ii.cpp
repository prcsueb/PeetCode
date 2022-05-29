class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        map<int,int> lookup;
        for(int i=idx;i<nums.size();i++) {
            if(lookup.find(nums[i]) == lookup.end()) {
                lookup[nums[i]]++;
                swap(nums[idx], nums[i]);
                helper(nums,idx+1);
                swap(nums[idx], nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(nums,0);
        return ans;
    }
};