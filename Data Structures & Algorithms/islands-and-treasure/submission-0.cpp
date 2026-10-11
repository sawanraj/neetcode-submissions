class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return;

        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>q;
        //Find all the treasure chest(0)
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
             if(grid[r][c]==0)
                q.push({r,c});   
            }
        }
        vector<pair<int,int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto [r,c]=q.front();// store index row and column
            q.pop();

            for(const auto& dir:directions){
                int nr=r+dir.first; //neighbor row
                int nc=c+dir.second;//neighbor col
                if(nr>=0 && nr<row && nc>=0 && nc <col && grid[nr][nc]==2147483647){
                    grid[nr][nc]=grid[r][c]+1;
                    q.push({nr,nc});
                }
            }
        } 
    }
};
