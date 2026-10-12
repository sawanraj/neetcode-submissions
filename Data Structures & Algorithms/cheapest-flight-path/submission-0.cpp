class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(const auto& flight:flights){
            int u=flight[0];
            int v=flight[1];
            int w=flight[2];

            adj[u].push_back({v,w});
        }
        vector<int>minprice(n,INT_MAX);
        minprice[src]=0;

        queue<pair<int,int>>q;
        q.push({src,0});
        int stops=0;

        while(!q.empty() && stops<=k){
            int size=q.size();

            for(int i=0;i<size;i++){
                auto [currcity,currcost]=q.front();
                q.pop();

                for(const auto& neighbor:adj[currcity]){
                    int nextcity=neighbor.first;
                    int price=neighbor.second;

                    if(currcost+price<minprice[nextcity]){
                        minprice[nextcity]=currcost+price;
                        q.push({nextcity,minprice[nextcity]});
                    }
                }
            }
            stops++;
        }
        return minprice[dst]==INT_MAX?-1:minprice[dst];
    }

};
