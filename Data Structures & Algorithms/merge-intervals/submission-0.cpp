class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int currentstart=intervals[i][0];
            int currentend=intervals[i][1];
            int lastend=ans.back()[1];
            if(currentstart <=lastend){
                //Overlapping
                ans.back()[1]=max(lastend,currentend);
            }else{
                //Non Overlapping
                ans.push_back(intervals[i]);
            }
        }
    return ans;
    }
};
