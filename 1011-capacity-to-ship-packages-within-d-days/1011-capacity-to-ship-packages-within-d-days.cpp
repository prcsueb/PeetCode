class Solution {
public:
    bool canBeAns(vector<int>& weights, int mid, int days) {
        int d = 1;
        int sum = 0;
        for(int i=0;i<weights.size();i++) {
            sum += weights[i];
            if(sum > mid) {
                d++;
                sum = weights[i];
            }
        }
        
        return d <= days; //jitne din lag rhe hai usse kam hai then it's possible otherwise return false
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxx = 0;
        int sum = 0;
        
        for(int i=0;i<weights.size();i++) {
            sum += weights[i];
            maxx = max(maxx, weights[i]);
        }
        
        if(weights.size() == days) {
            return maxx;
        }
        
        int low = maxx;
        int high = sum;
        int ans = INT_MAX;
        while(low <= high) {
            int mid = (low+high)/2;
            if(canBeAns(weights,mid,days)) {
                ans = min(ans, mid);
                high=mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return ans;
    }
};