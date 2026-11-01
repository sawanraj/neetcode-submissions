class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int>visited(n,false);
        int totalcost=0;
        int nodeused=0;

        while(!pq.empty() && nodeused<n){
            auto [cost,node]=pq.top();
            pq.pop();

            if(visited[node]==true)
            continue;

            visited[node]=true;
            totalcost+=cost;
            nodeused++;
            for(int next=0;next<n;next++){
                if(visited[next])
                    continue;
                int distance=abs(points[node][0]-points[next][0])+abs(points[node][1]-points[next][1]);
                pq.push({distance,next});
            }
        }
    return totalcost;
    }
};
