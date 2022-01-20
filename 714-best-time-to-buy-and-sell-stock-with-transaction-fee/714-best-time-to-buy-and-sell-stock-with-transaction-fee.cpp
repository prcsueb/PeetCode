class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int oldBuyingStateProfit = -prices[0];
        int oldSellingStateProfit=0;
        
        for(int i=1;i<prices.size();i++) {
            int newBuyingStateProfit=0;
            int newSellingStateProfit=0;
            if(oldBuyingStateProfit > oldSellingStateProfit-prices[i]) {
                newBuyingStateProfit = oldBuyingStateProfit;
            } else {
                newBuyingStateProfit = oldSellingStateProfit-prices[i];
            }
            
            if(oldSellingStateProfit > oldBuyingStateProfit+prices[i]-fee) {
                newSellingStateProfit = oldSellingStateProfit;
            } else {
                newSellingStateProfit = oldBuyingStateProfit+prices[i]-fee;
            }
            oldBuyingStateProfit = newBuyingStateProfit;
            oldSellingStateProfit = newSellingStateProfit;
            
        }
        
        return oldSellingStateProfit;
    }
};