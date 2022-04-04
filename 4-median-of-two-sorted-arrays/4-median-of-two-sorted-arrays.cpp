class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        if(n == 0) {
            if(m % 2 == 1) {
                ans = nums2[m/2];
            } else {
                ans = nums2[m/2]+nums2[(m/2)-1];
                ans /= 2;
            }
            return ans;
        }
        if(m == 0) {
            if(n % 2 == 1) {
                ans = nums1[n/2];
            } else {
                ans = nums1[n/2]+nums1[(n/2)-1];
                ans /= 2;
            }
            return ans;
        }
        
        if(m < n) {
            nums1.swap(nums2);
        }
        n = nums1.size();
        m = nums2.size();
        int low = 0 , high = n;
        int total = (n + m);
        while(low <= high) {
            int aleft = low + (high - low) / 2;
            int bleft  = (total+1)/2 - aleft;
            cout << aleft << "," << bleft << endl;
            int al = aleft == n ? INT_MAX : nums1[aleft];
            int alm1 = aleft == 0 ? INT_MIN : nums1[aleft-1];
            int bl = bleft == m ? INT_MAX : nums2[bleft];
            int blm1 = bleft == 0 ? INT_MIN : nums2[bleft-1];
            
            cout << al << "," << alm1 << "," << bl << "," << blm1 << endl;
            
            if(alm1 <= bl && blm1 <= al) {
                if(total % 2 == 0) {
                    int x = max(alm1,blm1);
                    int y = min(al,bl);
                    return (x+y)/2.0;
                } else {
                    return max(alm1,blm1) * 1.0;
                }
            } else if(alm1 > bl) {
                high = aleft - 1;
            } else if(blm1 > al) {
                low = aleft + 1;
            }
        }
        return ans;
    }
};