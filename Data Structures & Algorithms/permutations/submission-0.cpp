class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>result;
         generatepermutation(0,nums,result);

         return result;
    }
    void generatepermutation(int idx,vector<int>& nums, vector<vector<int>>&result){
        if(idx==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            generatepermutation(idx+1,nums,result);
            swap(nums[idx],nums[i]);
        }
    }
};
