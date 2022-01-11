class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start=0;
        int end=n-1;
        
        while(start<=end) {
            int mid=start+(end-start)/2;
            if(mid==0) {
            if(arr[mid]>arr[mid+1]) {
                return mid;
                } else {
                    return 1;
                }
            }
            if(mid==n-1) {
                if(arr[mid]>arr[mid-1]) {
                    return mid;
                } else {
                    return n-2;
                }
            }
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) {
                return mid;
            } else if(arr[mid]<arr[mid+1]) {
                start=mid+1;
            } else {
                end=mid-1;
            }
        }
        return -1;
    }
};