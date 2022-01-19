class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
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
                tempList.push_back(nums[i]);
                backtracking(list,tempList,nums,i,target-nums[i]);
                tempList.pop_back();
            }
        }
    }
};