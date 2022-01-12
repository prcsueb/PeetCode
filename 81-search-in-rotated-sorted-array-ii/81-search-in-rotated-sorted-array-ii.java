class Solution {
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        int lo = 0;
        int hi = n - 1;
        if(n==1) {
            if(target == nums[0]) {
                return true;
            } else {
                return false;
            }
        }
        while(lo <= hi){
            while(lo < hi && nums[lo] == nums[hi]) {
                lo++;
            }
            int mid = (lo+hi)/2;
            if(nums[lo] == target || nums[hi] == target || nums[mid] == target){
                return true;
            }
            if(nums[lo] <= nums[mid]){
                if(nums[lo] <= target && target < nums[mid]){
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
            }else if(nums[mid] <= nums[hi]){
                if(nums[mid] < target && target <= nums[hi]){
                    lo = mid + 1;
                }else{
                    hi = mid - 1;
                }
            }else{
                lo++;
            }
        }
        return false;
    }
}
// 11111333