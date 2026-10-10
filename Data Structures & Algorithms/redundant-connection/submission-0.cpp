class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>result;
        int n=edges.size();
        vector<int>parent(n+1);

        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];

            int rootu=findroot(u,parent);
            int rootv=findroot(v,parent);

            if(rootu==rootv){
                return edge;
            }
            else{
                parent[rootu]=rootv;
            }
        }
        return {};
    }
    int findroot(int i, vector<int>&parent){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=findroot(parent[i],parent);
    }

};
