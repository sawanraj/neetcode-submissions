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
        vector<int>dp(2*totalsum+1,0);
        int offset=totalsum;
        dp[offset]=1;
        //vector<vector<int>>dp(n,vector<int>(2*totalsum+1,-1));
        //return recurr(0,dp,nums,currentsum,target,totalsum); 
        for(int num:nums){
            vector<int>next(2*totalsum+1,0);
            for(int sum=-totalsum;sum<=totalsum;sum++){
                int way=dp[sum+offset];
                if(way>0){
                    if(sum+num<=totalsum)
                        next[sum+num+offset]+=way;
                    if(sum-num>=-totalsum)
                        next[sum-num+offset]+=way;
                }
            }
            dp=next;
        }
        return dp[target+offset];
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
