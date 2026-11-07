class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int insert=false;
        for(const auto& interval:intervals){
            if(interval[1]<newInterval[0]){
                //before
                ans.push_back(interval);
            }
            else if(newInterval[1]<interval[0]){
                //after
                if(!insert){
                    ans.push_back(newInterval);
                    insert=true;
                }
                ans.push_back(interval);
            }
            else{
                //Overlap
                newInterval[0]=min(newInterval[0],interval[0]);
                newInterval[1]=max(newInterval[1],interval[1]);
            }
        }
        if(!insert)
        ans.push_back(newInterval);

        return ans;
    }
};
