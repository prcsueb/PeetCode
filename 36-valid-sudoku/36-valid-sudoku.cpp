class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>st;
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    string s1="row"+to_string(i)+board[i][j];
                    string s2="column"+to_string(j)+board[i][j];
                    int ans=(i/3)*3+j/3;
                    string s3="box"+to_string(ans)+board[i][j];
                    if(st.count(s1) || st.count(s2) || st.count(s3))
                        return false;
                   st.insert(s1);
                    st.insert(s2);
                    st.insert(s3);
                }
            }
        }
        return true;
    }
};