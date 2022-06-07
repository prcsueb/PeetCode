// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    long helper(int n, vector<int> &dp) {
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        long ans = helper(n-1, dp) + helper(n-2, dp) * (n-1);
        return dp[n] = (int)(ans % (int)(1e9+7));
    }
    long countFriendsPairings(int n) 
    { 
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends