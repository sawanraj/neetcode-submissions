class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int>dp(amount+1,0);
        dp[0]=1;
        for(int coin:coins){
            for(int i=coin;i<=amount;i++){
                dp[i]+=dp[i-coin];
            }
        }
        //vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        //return recurr(0,dp,coins,amount);
    return dp[amount];
    }
    int recurr(int index,vector<vector<int>> &dp,vector<int>& coins,int amount){
        if(amount==0)
            return 1;
        if(index>=coins.size())
            return 0;

        if(dp[index][amount]!=-1)
            return dp[index][amount];

        int skip=recurr(index+1,dp,coins,amount);
        int take=0;
        if(coins[index]<=amount){
            take=recurr(index,dp,coins,amount-coins[index]);
        }
        dp[index][amount]=skip+take;

        return dp[index][amount];
    }
};
