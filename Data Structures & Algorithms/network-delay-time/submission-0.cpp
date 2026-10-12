class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        //build adjency list node with time
        for(const auto& t:times){
            int u=t[0];
            int v=t[1];
            int w=t[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto[currTime,u]=pq.top();
            pq.pop();

            if(currTime >dist[u])
                continue;

            for(const auto& edge:adj[u]){
                int v=edge.first;
                int weight=edge.second;

                if(dist[u]+weight<dist[v]){
                    dist[v]=dist[u]+weight;
                    pq.push({dist[v],v});
                }
            }
        }
        int maxDelay=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)
                return -1;
            maxDelay=max(maxDelay,dist[i]);
        }
    return maxDelay;
    }
};
