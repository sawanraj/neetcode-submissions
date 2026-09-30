class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>myset;

        for(int i=0;i<nums.size();i++){
            if(i>k){
                myset.erase(nums[i-k-1]);
            }
            if(myset.count(nums[i])){
                return true;
            }
            myset.insert(nums[i]);
        }
    return false;
    }
};