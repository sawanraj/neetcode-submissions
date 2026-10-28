class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int currentsum=0;
        int totalsum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        if(abs(target)>totalsum)
            return 0;
        vector<vector<int>>dp(n,vector<int>(2*totalsum+1,-1));
        return recurr(0,dp,nums,currentsum,target,totalsum); 
    }

    int recurr(int index,vector<vector<int>> &dp,vector<int>& nums,int currentsum,int target,int totalsum){
        if(index ==nums.size()){
            if(currentsum==target)
                return 1;

            return 0;
        }
        if(dp[index][currentsum+totalsum]!=-1)
            return dp[index][currentsum+totalsum];
        int plus=recurr(index+1,dp,nums,currentsum+nums[index],target,totalsum);
        int minus=recurr(index+1,dp,nums,currentsum-nums[index],target,totalsum);
        dp[index][currentsum+totalsum]=plus+minus;

        return dp[index][currentsum+totalsum];
    }
};
