class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int ns=1;
        for(int i=0;i<n;i++){
            ns*=2;
        }
        vector<vector<int>>result;
        //formation of set
        for(int i=0;i<ns;i++){
            vector<int>current_set;
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0){
                    current_set.push_back(nums[j]);
                }
            }
            result.push_back(current_set);
        }
    return result;
    }
};
