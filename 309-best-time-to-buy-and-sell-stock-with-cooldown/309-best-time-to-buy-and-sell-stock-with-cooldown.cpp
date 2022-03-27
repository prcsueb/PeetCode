class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bsp=-prices[0],ssp=0,cd=0;
        for(int i=1;i<prices.size();i++) {
            int new_bsp = max(bsp, cd-prices[i]);
            int new_ssp = max(ssp, prices[i]+bsp);
            int new_cd = max(cd, ssp);;
            cd = new_cd;
            bsp=new_bsp;
            ssp=new_ssp;
        }
        return ssp;
    }
};