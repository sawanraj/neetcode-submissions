class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>newnum(n+2,0);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        int left=0;
        int right=n+1;
        newnum[left]=1;
        newnum[right]=1;
        for(int i=1,j=0;i<right && j<n;i++,j++){
            newnum[i]=nums[j];
        }
        for(int gap=2;gap<=n+1;gap++){
            for(int left=0;left+gap<=n+1;left++){
                int right=left+gap;
                for(int k=left+1;k<right;k++){
                    int brust=dp[left][k]+newnum[left]*newnum[k]*newnum[right]+dp[k][right];
                    dp[left][right]=max(dp[left][right],brust);
                 }
            }
        }
        return dp[0][n+1];
        //vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        //return dfs(left,right,newnum);
        //return dfsdp(left,right,newnum,dp);
    }
    int dfsdp(int left,int right,vector<int> &newnum,vector<vector<int>> &dp){
        if(left+1 ==right)
        return 0;
        if(dp[left][right]!=-1)
        return dp[left][right];

        int maxcoin=0;
        for(int k=left+1; k<=right-1;k++){
            int leftcoin=dfsdp(left,k,newnum,dp);
            int rightcoin=dfsdp(k,right,newnum,dp);

            int lastbrust=newnum[left]*newnum[k]*newnum[right];
            int currentcoin=leftcoin+lastbrust+rightcoin;

            maxcoin=max(maxcoin,currentcoin);
        }
        dp[left][right]=maxcoin;

        return dp[left][right];
    }
    
};
