class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        
        for(int i=1;i<n;i++) {
            int last = ans.back();
            if(nums[i] > last) {
                ans.push_back(nums[i]);
            } else {
                int low = 0;
                int high = ans.size() - 1;
                int correctPlace = high;
                while(low <= high) {
                    int mid = low + (high - low) / 2;
                    if(ans[mid] >= nums[i]) {
                        correctPlace = mid;
                        high = mid-1;
                    } else {
                        low = mid + 1;
                    }
                }
                cout <<"correctPlace =" << correctPlace << endl;
                cout << "\n";
                ans[correctPlace] = nums[i];
            }
        }
        cout << "\n";
        for(auto x : ans) {
            cout << x << ",";
        }
        return ans.size();
    }
};