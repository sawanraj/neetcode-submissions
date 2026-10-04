class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minlen=INT_MAX;
        int sum=0;
        int j=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                minlen=min(minlen,i-j+1);
                sum-=nums[j];
                j++;
            }
        }
    return (minlen==INT_MAX)?0:minlen;
    }
};