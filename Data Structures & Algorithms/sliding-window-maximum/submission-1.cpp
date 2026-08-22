class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     vector<int>result;
     int n=nums.size();
     int maxele=INT_MIN;
     deque<int>dq;
     int r=0;
     while(r<n){
        //Remove index which is out of k window
        if(!dq.empty() && dq.front() == r-k){
            dq.pop_front();
        }
        //Remove smaller elements from the back as they are useless
        while(!dq.empty() && nums[dq.back()] <= nums[r]){
            dq.pop_back();
        }
        //Push the index of current element
        dq.push_back(r);
        //append max to result once the window of size k is fromed.
        if(r>=k-1){
            result.push_back(nums[dq.front()]);
        }
        r++;
     }
    return result;
    }
};
