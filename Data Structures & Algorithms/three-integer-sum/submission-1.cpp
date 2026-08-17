class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());//sort first then apply two pointer
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] ==nums[i-1])
            continue;

            int j=i+1;//left
            int k=n-1;//right
            while(j<k){
                int currentsum=nums[i]+nums[j]+nums[k];
                if(currentsum == 0){
                    result.push_back({nums[i],nums[j],nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;
                }
                else if(currentsum >0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
    return result;
    }
};
