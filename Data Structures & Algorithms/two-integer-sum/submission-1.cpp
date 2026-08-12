class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        unordered_map <int,int> present;
        for(int i=0;i<len;i++){
            int key=target-nums[i];
            if(present.count(key))
                return {present[key],i};

            present[nums[i]]=i;
        }
    return {};
    }
};
