class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0} ,{0, 1}};
    void helper(vector<vector<int>>& image, int target, int sr, int sc, int newColor, vector<vector<int>> &visited) {
        image[sr][sc]=newColor;
        visited[sr][sc] = 1;
        for(int i=0;i<dir.size();i++) {
            int newRow = sr + dir[i][0];
            int newCol = sc + dir[i][1];

            if(newRow >=0 && newCol >= 0 && newRow < image.size() && newCol < image[0].size() && image[newRow][newCol] == target && visited[newRow][newCol] == -1) {
                helper(image, target, newRow, newCol, newColor, visited);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), -1));
        if(image[sr][sc] != image[sr][sc]) {
            return image;
        }
        helper(image, image[sr][sc], sr, sc, newColor, visited);
        return image;
    }
};