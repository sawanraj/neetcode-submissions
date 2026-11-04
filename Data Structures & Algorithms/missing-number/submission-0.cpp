class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing=0;
        int n=nums.size();
        int start=0;
        missing=n;

        for(start=0;start<n;start++){
            missing^=start;
            missing^=nums[start];
        }
        return missing;
    }
};
