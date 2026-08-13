class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        /*Frequency of each element*/
        for(int x: nums)
            freq[x]++;
        
        vector<vector<int>> bucket(nums.size()+1);/*2-D vector for storing element and its count*/
        for(auto &[val,count]:freq)
            bucket[count].push_back(val);

        vector<int>result;
        /*Copy the frquent K element in Result vector*/
        for(int c=nums.size();c>=1 && result.size()<k;c--)
            for(int v:bucket[c]){
                result.push_back(v);
                if(result.size()==k)
                    break;            
            }
    return result;
    }
};
