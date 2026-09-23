class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>current;
        vector<vector<int>>result;
        //Sort the input array to group duplicate element togather
        sort(nums.begin(),nums.end());
        generatesubset(0,nums,current,result);

        return result;
    }
    void generatesubset(int idx, vector<int>&nums,vector<int>&current,vector<vector<int>>&result){
            //Below is final result building
            result.push_back(current);
            for(int i=idx;i<nums.size();i++){
                //Skip the duplicate at the same level
                if(i>idx && nums[i]==nums[i-1])
                    continue;
                current.push_back(nums[i]);
                generatesubset(i+1,nums,current,result);
                //Backtrack and pop the 
                current.pop_back();
            }
            
    }
};
