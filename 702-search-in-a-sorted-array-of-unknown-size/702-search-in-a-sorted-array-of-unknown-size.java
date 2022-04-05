/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *     public int get(int index) {}
 * }
 */

class Solution {
    public static int binarySearch(ArrayReader reader, int lower, int upper, int target) {
        int ans = -1;
        while(lower <= upper) {
            int mid = lower + (upper - lower)/2;
            if(reader.get(mid) == target) {
                ans = mid;
                break;
            } else if(reader.get(mid) > target) {
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        }
        return ans;
    }
    public int search(ArrayReader reader, int target) {
        
        int low = 0;
        int high = 1;
        int ans = -1;
        
        while(reader.get(high) < target) {
            low = high;
            high = high * 2;
        }
        
        ans = binarySearch(reader, low, high, target);
        
        return ans;
    }
}