// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int W, int wt[], int val[], int n, vector<vector<int>> &dp, int idx) {
        if(W == 0) { return 0; }
        if(idx == n) {
            return 0;
        }
        
        if(dp[W][idx] != -1) {
            return dp[W][idx];
        }
        
        int left = 0;
        int right = 0;
        if(W - wt[idx] >= 0) {
            left = val[idx] + helper(W - wt[idx], wt, val, n, dp, idx+1);
        }
        right = helper(W, wt, val, n, dp, idx+1);
        
        return dp[W][idx] = max(left, right);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(W+1,vector<int>(n+1, -1));
       int ans = helper(W, wt, val, n, dp, 0);
       return ans;
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends