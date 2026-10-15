class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==0)
            return 0;
        if(n==1)
            return nums[0];

        int misslast=robhelper(nums,0,n-2);
        int missfirst=robhelper(nums,1,n-1);

    return max(misslast,missfirst);
    }
    int robhelper(vector<int>& nums, int start, int end){
        int prev2=0;
        int prev1=0;

        for(int i=start;i<=end;i++){
            int current=max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=current;
        }
    return prev1;
    }
};
