class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int hold=INT_MIN/2;
        int sell=0;
        int cooldown=0;

        for(int p:prices){
            int prevsell=sell;
            sell=hold+p;
            hold=max(hold,cooldown-p);
            cooldown=max(cooldown,prevsell);
        }
        return max(sell,cooldown);
        //vector<vector<int>>dp(n,vector<int>(2,-1));
        //return dfs(0,1,prices,dp);
    }
    int dfs(int index,int cnbuy,vector<int>& prices,vector<vector<int>> &dp){
        if(index>=prices.size())
        return 0;

        if(dp[index][cnbuy]!=-1)
        return dp[index][cnbuy];

        int cooldown=dfs(index+1,cnbuy,prices,dp);

        if(cnbuy){
            int buy=dfs(index+1,0,prices,dp)-prices[index];
            dp[index][cnbuy]=max(buy,cooldown);
        }
        else{
            int sell=dfs(index+2,1,prices,dp)+prices[index];
            dp[index][cnbuy]=max(sell,cooldown);
        }
    return dp[index][cnbuy];
    }
};
