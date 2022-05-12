class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> store;
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            if(store.find(target - nums[i]) != store.end()) {
                ans.push_back(i);
                ans.push_back(store[target-nums[i]]);
            } else {
                store[nums[i]] = i;
            }
        }
        
        return ans;
    }
};