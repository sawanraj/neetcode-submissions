class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curmax=nums[0];
        int curmin=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)
            {
                swap(curmax,curmin);
            }
                curmax=max(nums[i],curmax*nums[i]);
                curmin=min(nums[i],curmin*nums[i]);
                ans=max(ans,curmax);
        }
        return ans;
    }
};
