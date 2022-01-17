class Solution {
public:
    bool canDivide(vector<int>& s, int k, int mid) {
        int sum=0;
        int d=0;
        for(int i=0;i<s.size();i++) {
            sum+=s[i];
            if(sum>mid) {
                d++;
                sum=0;
            }
        }
        if(d>k)return false;
        return true;
    }
    int maximizeSweetness(vector<int>& s, int k) {
        int low=0;
        int sum=0;
        for(int i=0;i<s.size();i++) {
            sum+=s[i];
        }
        // k++;
        int high=sum;
        int ans=0;
        while(low<=high) {
            int mid=low+(high-low)/2;
            bool canD = canDivide(s,k,mid);
            if(canD) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};