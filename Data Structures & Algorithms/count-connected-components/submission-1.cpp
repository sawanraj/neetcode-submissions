class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjlist(n);

        for(const auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<bool>visited(n,false);
        int componentcount=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                componentcount++;
                dfs(i,adjlist,visited);
            }
        }
    return componentcount;
    }
    void dfs(int node, const vector<vector<int>>&adjlist,vector<bool>&visited){
        visited[node]=true;
        for(int neighbor:adjlist[node]){
            if(!visited[neighbor]){
                dfs(neighbor,adjlist,visited);
            }
        }
    }
};
