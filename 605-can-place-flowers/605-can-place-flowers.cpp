class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        for(int i=0;i<N;i++) {
            if(flowerbed[i] == 0) {
                bool isLeftZero = (i==0) || (flowerbed[i-1]==0) ? true : false;
                bool isRightZero = (i==N-1) || (flowerbed[i+1]==0) ? true : false;
                if(isLeftZero && isRightZero) {
                    flowerbed[i]=1;
                    n--;
                    if(n <= 0) return true;
                }
            }
        }
        return n <= 0 ? true : false;
    }
};