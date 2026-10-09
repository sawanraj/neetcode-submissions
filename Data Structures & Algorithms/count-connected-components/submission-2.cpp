class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>parent(n);
        iota(parent.begin(),parent.end(),0);
        int componentcount=n;

        for(const auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            
            int rootu=findroot(u,parent);
            int rootv=findroot(v,parent);

            if(rootu!=rootv){
                parent[rootu]=rootv;
                componentcount--;
            }
        }
    return componentcount;
    }
    int findroot(int i,vector<int>&parent){
       if(parent[i]==i)
        return i;

        return parent[i]=findroot(parent[i],parent);
    }
};
