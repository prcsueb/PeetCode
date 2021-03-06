class Solution {
public:
    int checkAns(vector<int>& ribbons, int mid) {
        int count=0;
        for(auto x : ribbons) {
            count+=(x/mid);
        }
        return count;
    }
    int maxLength(vector<int>& ribbons, int k) {
        long long n=ribbons.size();
        long long low=1;
        long long sum=0;
        for(long long i=0;i<n;i++) {
            sum+=ribbons[i];
        }
        
        long long high=sum;
        int ans=INT_MIN;
        while(low<=high) {
            long long mid=low+(high-low)/2;
            long long count = checkAns(ribbons,mid);
            cout << low << " , " << high << " , " << count << " , " << mid << endl;
            if(count>=k) {
                if(mid>ans) {
                    ans=mid;
                }
            }
            if(count<k) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans==INT_MIN?0:ans;
    }
};