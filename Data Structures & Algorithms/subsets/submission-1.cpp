class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>current_set;
        vector<vector<int>>result;

        generate_subset(0,nums,current_set,result);
    return result;
    }
    void generate_subset(int index,vector<int>&nums,vector<int>&current_set,vector<vector<int>>&result){
        if(index == nums.size()){
            result.push_back(current_set);
            return;
        }
        //Include
        current_set.push_back(nums[index]);
        generate_subset(index+1,nums,current_set,result);
        //Exclude 
        current_set.pop_back();
        generate_subset(index+1,nums,current_set,result);

    }
};
