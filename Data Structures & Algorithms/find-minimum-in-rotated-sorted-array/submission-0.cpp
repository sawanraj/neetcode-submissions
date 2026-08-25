class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int minelement=INT_MAX;
        while(l<=h){
            if(nums[l] <= nums[h]){
                minelement=min(minelement,nums[l]);
                break;
            }
            int m=l+(h-l)/2;
            minelement=min(minelement,nums[m]);
            if(nums[l] <=nums[m]){
                minelement=min(minelement,nums[m]);
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
    return minelement;
    }
};
