// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    // code here
	    vector<int> lis(n, 0);
	    vector<int> dis(n, 0);
	    
	    lis[0] = 1;
	    for(int i=1;i<n;i++) {
	        for(int j=i-1;j>=0;j--) {
	            if(nums[i] > nums[j]) {
	                lis[i] = max(lis[i], lis[j]);
	            }
	        }
	        lis[i]++;
	    }
	    
	    dis[n-1] = 1;
	    for(int i=n-2;i>=0;i--) {
	        for(int j=i+1;j<n;j++) {
	            if(nums[i] > nums[j]) {
	                dis[i] = max(dis[i], dis[j]);
	            }
	        }
	        dis[i]++;
	    }
	    
	    int sum=0;
	    for(int i=0;i<n;i++) {
	        sum = max(sum, lis[i] + dis[i]);
	    }
	    return sum-1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends