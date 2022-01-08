class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {

        long long sum = 0;
        for(int i=0;i<ribbons.size();i++) {
            sum += ribbons[i];
        }
        if(sum<k)return 0;
        long long low = 1, high = sum;
        while(low <= high){
            long long mid = low + (high-low) / 2;
            long long count = totalPeice(ribbons, k , mid);
            if(count < k){
                high = mid - 1;
            }else{
                low= mid + 1;
            }
        }
        return high;
    }
    int totalPeice(vector<int>& ribbons, int k, int value){
        int count = 0;
        for(int ele : ribbons){
            count += ele / value;
        }
        return count;
    }
};