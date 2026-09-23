class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>current;
        //sorting make all duplicate togather
        sort(candidates.begin(),candidates.end());
        combinationcreator(0,target,candidates,current,result);
        return result;
    }
    void combinationcreator(int idx, int target,vector<int>& candidates,vector<int>&current,vector<vector<int>>&result){
        //base condition1 where all target meet
        if(target == 0){
            result.push_back(current);
            return;
        }
        //base condition2 where indec matched to size
        if(idx==candidates.size() || target <0)
           return;
        current.push_back(candidates[idx]);
        combinationcreator(idx+1,target-candidates[idx],candidates,current,result);

        current.pop_back();
        //Remove all duplicte
        int idx_new=idx+1;
        while(idx_new <candidates.size() && candidates[idx_new] ==  candidates[idx]){
            idx_new++;
        }
        combinationcreator(idx_new,target,candidates,current,result);
    }
};
