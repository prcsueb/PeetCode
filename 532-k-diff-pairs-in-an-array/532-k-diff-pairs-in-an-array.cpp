class Solution {
public:
    int bs(vector<int>& nums, int low, int high, int diff) {
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == diff) {
                return mid;
            } else if(nums[mid] > diff) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int diff = k + nums[i];
            int chk = bs(nums, i+1, n-1, diff);
            if(chk != -1) ans++;
        }
        return ans;
    }
};