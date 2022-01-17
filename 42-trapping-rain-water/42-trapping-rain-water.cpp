class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while(left < right) {
            if(leftMax < height[left]) {
                leftMax = height[left];
            }
            if(rightMax < height[right]) {
                rightMax = height[right];
            }
            
            if(leftMax < rightMax) {
                ans += leftMax - height[left];
                left++;
            } else {
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};