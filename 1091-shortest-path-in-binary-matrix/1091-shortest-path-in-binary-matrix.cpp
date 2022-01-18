class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{1,-1},{-1,1},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0 || grid[grid.size()-1][grid[0].size()-1] != 0) {
            return -1;
        }
        queue<tuple<int,int,int>> q; //{row,col,steps}
        q.push(make_tuple(0,0,1));
        grid[0][0]=1;
        
        while(!q.empty()) {
            auto [row,col,steps] = q.front();
            q.pop();
            if(row==grid.size()-1 && col==grid[0].size()-1) {
                return steps;
            }
            for(auto d : dir) {
                int newRow = row+d[0];
                int newCol = col+d[1];
                if(newRow>=0 && newCol>=0 && newRow<grid.size() && newCol<grid[0].size() && grid[newRow][newCol]==0) {
                    q.push(make_tuple(newRow,newCol,steps+1));
                    grid[newRow][newCol]=1;
                }
            }
        }
        
        return -1;
    }
};