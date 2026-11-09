class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int prevend=intervals[0][1];
        int count=0;

        for(int i=1;i<intervals.size();i++){
            int currentstart=intervals[i][0];
            int currentend=intervals[i][1];
            if(currentstart<prevend){
                count++;
                prevend=min(prevend,currentend);
            }else{
                
                prevend=currentend;
            }
        }
    return count;
    }
};
