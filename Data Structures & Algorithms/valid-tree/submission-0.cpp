class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        if(edges.size()!=n-1){
            return false;
        }
        vector<vector<int>>adjlist(n);
        for(const auto & edge:edges){
            int u=edge[0];
            int v=edge[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        queue<int>qp;
        qp.push(0);
        vector<bool>visited(n);
        visited[0]=true;
        int visitcount=1;
        while(!qp.empty()){
            auto node=qp.front();
            qp.pop();
            for(int neighbor:adjlist[node] ){
                if(visited[neighbor]!=true){
                    visited[neighbor]=true;
                    visitcount++;
                    qp.push(neighbor);

                }
            }
        }
    return visitcount==n?true:false;
    }
};
