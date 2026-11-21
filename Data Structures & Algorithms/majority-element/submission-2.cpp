class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*int n=nums.size();
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        for(int num:nums){
            if(freq[num]>n/2)
              {
                  return num;
              }
        }*/
        int candidate=0;
        int count=0;
        for(int num:nums){
            if(count==0){
                candidate=num;
            }
            if(num==candidate){
                count++;
            }
            else{
                count--;
            }
        }
    return candidate;
    }
};