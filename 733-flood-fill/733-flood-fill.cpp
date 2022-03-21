class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0} ,{0, 1}};
    void helper(vector<vector<int>>& image, int target, int sr, int sc, int newColor) {
        image[sr][sc]=newColor;
        for(int i=0;i<dir.size();i++) {
            int newRow = sr + dir[i][0];
            int newCol = sc + dir[i][1];

            if(newRow >=0 && newCol >= 0 && newRow < image.size() && newCol < image[0].size() && image[newRow][newCol] == target) {
                helper(image, target, newRow, newCol, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor) {
            helper(image, image[sr][sc], sr, sc, newColor);
        }
        return image;
    }
};