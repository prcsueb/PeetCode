// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int n, int *arr, int start, int end, vector<vector<int>> &dp) {
        if(start + 1 == end) {
            return dp[start][end] = 0;
        }
        if(dp[start][end]!=0) return dp[start][end];
        
        int minAns = INT_MAX;
        for(int cut=start+1;cut<end;cut++) {
            int left = helper(n, arr, start, cut, dp);
            int right = helper(n, arr, cut, end, dp);
            int ans = left+right+arr[start]*arr[end]*arr[cut];
            minAns = min(minAns, ans);
        }
        return dp[start][end]=minAns;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        return helper(N, arr, 0, N-1, dp) ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends