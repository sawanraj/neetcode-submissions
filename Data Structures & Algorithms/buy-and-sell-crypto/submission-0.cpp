class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int n=prices.size();
        /*buy day price*/
        for(int i=0;i<n;i++){
            /*Sell day price*/
            for(int j=i+1;j<n;j++){
                int profit=prices[j]-prices[i];
                if(profit<0)
                    profit=0;

                if(profit>maxprofit){
                    maxprofit=profit;
                }
            }
        }
    return maxprofit;
    }
};
