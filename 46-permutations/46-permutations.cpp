class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> tempList;
        sort(nums.begin(),nums.end());
        backtracking(list,tempList,nums);
        return list;
    }
    void backtracking(vector<vector<int>> &list, vector<int> &tempList, vector<int> &nums) {
        if(tempList.size()==nums.size()) {
            list.push_back(tempList);
        }
        else {
            for(int i=0;i<nums.size();i++) {
                if(find(tempList.begin(),tempList.end(),nums[i]) != tempList.end()) {
                    continue;
                }
                tempList.push_back(nums[i]);
                backtracking(list,tempList,nums);
                tempList.pop_back();
            }
        }
    }
};