class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>current;
        vector<vector<int>>result;
        
        combinationfortarget(0,target,nums,current,result);
        return result;
    }
    void combinationfortarget(int idx,int target,vector<int>&nums,vector<int>&current,vector<vector<int>>&result){
      //Base condition 1
      if(target ==0){
        result.push_back(current);
        return;
      }
      //base condition 2
      if(idx == nums.size() || target <0)
      return;
      //Include
      current.push_back(nums[idx]);
      combinationfortarget(idx,target-nums[idx],nums,current,result);
      //Exclude
      current.pop_back();
      combinationfortarget(idx+1,target,nums,current,result);
    }
};
