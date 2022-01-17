class Solution {
public:
    bool canDivide(vector<int>& weights, int days, int mid) {
        int d=1;
        int sum=0;
        for(int i=0;i<weights.size();i++) {
            sum+=weights[i];
            if(sum>mid) {
                d++;
                sum=weights[i];
            }
        }
        if(d > days) {
            return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int low=0;
        for(int i=0;i<weights.size();i++) {
            sum+=weights[i];
            low=max(low,weights[i]);
        }
        
        int high=sum;
        int ans=0;
        while(low<=high) {
            int mid=low+(high-low)/2;
            bool canD = canDivide(weights,days,mid);
            if(canD) {
                high=mid-1;
                ans=mid;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};