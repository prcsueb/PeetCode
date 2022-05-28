class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    void helper(vector<vector<int>>& image, int sr, int sc, int newColor, int sameColor) {
        image[sr][sc]=newColor;
        for(auto d: dir) {
            int r = sr + d[0];
            int c = sc + d[1];
            if(r >= 0 && c >= 0 && r < image.size() && c < image[0].size() && image[r][c] == sameColor) {
                helper(image,r,c,newColor,sameColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor) {
            helper(image, sr, sc, newColor, image[sr][sc]);
        }
        return image;
    }
};