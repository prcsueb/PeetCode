class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> list;
        vector<int> tempList;
        sort(nums.begin(),nums.end());
        backtracking(list,tempList,nums,0,target);
        return list;
    }
    void backtracking(vector<vector<int>> &list, vector<int> &tempList, vector<int> &nums, int start, int target) {
        if(target<0) {
            return;
        }
        else if(target==0) {
            list.push_back(tempList);
        }
        else {
            for(int i=start;i<nums.size();i++) {
                if(i>start && nums[i]==nums[i-1]) continue;
                tempList.push_back(nums[i]);
                backtracking(list,tempList,nums,i+1,target-nums[i]);
                tempList.pop_back();
            }
        }
    }
};