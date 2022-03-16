class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}};
    int mazePaths(int sr, int sc, int er, int ec, vector<vector<int>> &dp) {
    if (er == sr && ec == sc) {
        dp[sr][sc] = 1;
        return dp[sr][sc];
    }
    if (dp[sr][sc] != 0) {
        return dp[sr][sc];
    }
    int counter = 0;
    for (auto d : dir) {
        int newX = sr + d[0];
        int newY = sc + d[1];
        if (newX >= 0 && newY >= 0 && newX < dp.size() && newY < dp[0].size()) {
            counter += mazePaths(newX, newY, er, ec, dp);
        }
    }

    return dp[sr][sc] = counter;
}
// int mazePathsMM(int sr, int sc, int er, int ec, vector<vector<int>> &dp) {
//         for (int startRow = er; startRow >= sr; startRow--) {
//             for (int startCol = ec; startCol >= sc; startCol--) {
//                 if (er == sr && ec == sc) {
//                     dp[startRow][startCol] = 1;
//                     continue;
//                 }
//                 int counter = 0;
//                 // cout << m << " " << n << endl;
//                 for (auto d : dir) {
//                     int newX = startRow + d[0];
//                     int newY = startCol + d[1];
//                     if (newX >= 0 && newY >= 0 && newX < dp.size() && newY < dp[0].size()) {
//                         counter += dp[newX][newY];
//                     }
//                 }

//                 dp[startRow][startCol] = counter;
//             }
//         }
//         return dp[sr][sc];
// }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp3(m, vector<int>(n, 0));
        int ans4 = mazePaths(0, 0, m-1, n-1, dp3);
        return ans4;
    }
};