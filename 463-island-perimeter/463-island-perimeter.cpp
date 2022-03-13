class Solution {
public:
 
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int totalOnes = 0;
        int onesMinus = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    ++totalOnes;
                   for(auto d : dirs) {
                        int newX = i + d[0];
                        int newY = j + d[1];
                        if(newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == 1) {
                            ++onesMinus;
                        }
                    }
                }
            }
        }    
        return (totalOnes*4) - onesMinus;
    }
};