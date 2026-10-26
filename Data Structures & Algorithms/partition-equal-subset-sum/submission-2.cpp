class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        if(totalsum%2 !=0)
            return false;
        int target=totalsum/2;
        vector<int>dp(target+1,false);
        dp[0]=true;
        //int index=0;
        //return recurr(index,target,nums,dp);
        for(int i=0;i<n;i++){
            for(int j=target;j>=nums[i];j--){
                dp[j]=dp[j] || dp[j-nums[i]];
            }
        }
        return dp[target];
    }
    bool recurr(int index, int target,vector<int>& nums,vector<vector<int>> &dp){
        if(target==0)
            return true;

        if(index>=nums.size() || target <0)
            return false;

        if(dp[index][target]!=-1)
            return dp[index][target];

        bool res=recurr(index+1,target,nums,dp) || recurr(index+1,target-nums[index],nums,dp);

        return dp[index][target]=res;
    }
};
