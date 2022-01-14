class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //1.sort nums array
        if(nums.size()<3)return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        //if there are only there elements so nums.size()-2
        //run till 3rd last element
        for(int i=0;i<nums.size()-2;i++) {
            //for array -2,-2,-1,-1,-1,-1,0,1
            //-2 ek var process thai gyo che so next time -2 process no thavo joye
            if(i==0 || (i>0 && nums[i]!=nums[i-1])) {
                int low=i+1;
                int high=nums.size()-1;
                int sum=0-nums[i];
                while(low<high) {
                    
                    if(sum == nums[low]+nums[high]) {
                        vector<int> answer;
                        answer.push_back(nums[i]);
                        answer.push_back(nums[low]);
                        answer.push_back(nums[high]);
                        ans.push_back(answer);
                        
                        while(low < high && nums[low]==nums[low+1]) {
                            low++;
                        }
                        while(low<high && nums[high]==nums[high-1]) {
                            high--;
                        }
                        high--;
                        low++;
                        
                    } else if((nums[low]+nums[high])<sum) {
                        low++;
                    } else {
                        high--;
                    }
                    
                }
            }
        }
        return ans;
    }
};