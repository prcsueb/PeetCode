class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int l = 0;
        int h = height.size()-1;
        while(l < h) {
            int area = min(height[l], height[h])*(h-l);
            max_area = max(max_area, area);
            if(height[l] > height[h]) {
                h--;
            } else if(height[l] < height[h]) {
                l++;
            } else {
                l++;
            }
        }
        return max_area;
    }
};