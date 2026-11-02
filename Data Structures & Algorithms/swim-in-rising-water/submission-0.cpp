class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int directions[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
      
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});

        int totaltime=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        while(!pq.empty()){
            auto top=pq.top();
            int currenttime=top.first;
            int u=top.second.first;
            int v=top.second.second;
            pq.pop();
            totaltime=max(totaltime,currenttime);
            //if(visited[u][v])
           //continue;
           if(u==n-1 && v==m-1){
                return totaltime;
           }
           for(const auto &direct:directions){
                int nr=u+direct[0];
                int nc=v+direct[1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && visited[nr][nc]==false){
                    pq.push({grid[nr][nc],{nr,nc}});
                    visited[nr][nc]=true;
                }
            }
        }
    return totaltime;
    }
};
