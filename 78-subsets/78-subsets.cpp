class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> tempList;
        sort(nums.begin(),nums.end());
        backtracking(list,tempList,nums,0);
        return list;
    }
    void backtracking(vector<vector<int>> &list, vector<int> &tempList, vector<int> &nums, int start) {
        list.push_back(tempList);
        for(int i=start;i<nums.size();i++) {
            tempList.push_back(nums[i]);
            backtracking(list,tempList,nums,i+1);
            tempList.pop_back();
        }
    }
};