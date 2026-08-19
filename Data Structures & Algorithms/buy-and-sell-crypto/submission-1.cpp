class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int n=prices.size();
        int j=0;
        /*Range price day*/
        for(int i=1;i<n;i++){
            if(prices[i] >prices[j]){
                int profit=prices[i]-prices[j];
                maxprofit=max(profit,maxprofit);
            }
            else{
                j=i;
            }
        }  
    return maxprofit;
    }
};
