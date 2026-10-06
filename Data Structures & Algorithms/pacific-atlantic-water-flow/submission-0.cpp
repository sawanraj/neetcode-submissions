class Solution {
    int row;
    int col;
    vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>result;
        if(heights.empty() || heights[0].empty())
            return result;

        row=heights.size();
        col=heights[0].size();
        vector<vector<bool>>pacific(row,vector<bool>(col,false));
        vector<vector<bool>>atlantic(row,vector<bool>(col,false));
        //process Top and bottom rows
        for(int c=0;c<col;c++){
            dfs(0,c,pacific,heights[0][c],heights);
            dfs(row-1,c,atlantic,heights[row-1][c],heights);
        }
        //process left and rights
        for(int r=0;r<row;r++){
            dfs(r,0,pacific,heights[r][0],heights);
            dfs(r,col-1,atlantic,heights[r][col-1],heights);
        }
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(pacific[r][c] && atlantic[r][c]){
                    result.push_back({r,c});
                }
            }
        }
    return result;
    }
    void dfs(int r,int c, vector<vector<bool>>&visited,int prev_height, vector<vector<int>>& heights ){
        if(r<0 || r>=row || c<0 || c>=col || visited[r][c] || heights[r][c] < prev_height){
            return;
        }
        visited[r][c]=true;

        for(const auto& [dr,dc]:directions){
            dfs(r+dr,c+dc,visited, heights[r][c],heights);
        }
    }
};
