class Solution {
public:
    class Pair{
      public:
        int row,col,data;
        Pair(int row,int col,int data) {
            this->row=row;
            this->col=col;
            this->data=data;
        }
    };
    
    class Compare {
        public:
        bool operator()(Pair a, Pair b) {
            return a.data > b.data;
        }
    };
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        priority_queue<Pair,vector<Pair>,Compare> pq;
        //insert first element of every row
        for(int i=0;i<n;i++) {
            pq.push(Pair(i,0,mat[i][0]));
        }
        
        int ans=-1;
        while(k > 0) {
            k--;
            Pair top = pq.top();
            pq.pop();
            int row = top.row;
            int col = top.col;
            int data = top.data;
            ans = data;
            if(col+1 < mat[0].size()) {
                pq.push(Pair(row,col+1,mat[row][col+1]));
            }
        }
        
        return ans;
    }
};