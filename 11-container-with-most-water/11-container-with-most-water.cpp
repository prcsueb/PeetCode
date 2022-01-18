class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int area=0;
        while(i<j) {
            area=max(area,(j-i)*min(height[i],height[j]));
            if(height[i]>height[j]) {
                j--;
            } else {
                i++;
            }
        }
        
        return area;
    }
};