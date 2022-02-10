class Solution {
public:
    long long sum(long long n) {
        return n*(n+1)/2;
    }
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60,0);
        for(int i=0;i<time.size();i++) {
            count[time[i]%60]++;
        }
        int ans=0;
        for(int i=1;i<=29;i++) {
            ans+=(count[i]*count[60-i]);
        }
        ans+=sum(count[0]-1);
        ans+=sum(count[30]-1);
        return ans;
    }
};