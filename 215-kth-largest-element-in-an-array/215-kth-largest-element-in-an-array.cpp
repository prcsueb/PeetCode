class Solution {
public:
    int partition(vector<int>& nums, int pivot, int low, int high) {
        int i = low, j = low;
        while(i <= high) {
            if(nums[i] > pivot) {
                i++;
            } else {
                swap(nums[i++], nums[j++]);
            }
        }
        return j-1;
    }
    int quickSelect(vector<int>& nums, int k, int low, int high) {
        int pivot = nums[high];
        int idx = partition(nums, pivot, low, high);
        if(k > idx) {
            return quickSelect(nums, k, idx+1, high);
        } else if(k < idx) {
            return quickSelect(nums, k, low, idx-1);   
        } 
        return pivot;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, nums.size() - k, 0, nums.size()-1);
    }
};