class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>>qs;
        for(int i=0;i<queries.size();i++)
        {
            qs.push_back({queries[i],i});
        }
        sort(qs.begin(),qs.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        vector<int>ans(queries.size(),-1);
        int i=0;
        for(const auto &[qr,idx]:qs){
            while(i<intervals.size() && intervals[i][0]<=qr){
                int start=intervals[i][0];
                int end=intervals[i][1];

                minheap.push({end-start+1,end});
                i++;
            }
            while(!minheap.empty() && minheap.top().second <qr){
                minheap.pop();
            }
            if(!minheap.empty()){
                ans[idx]=minheap.top().first;
            }
        }
    return ans;
    }
};
