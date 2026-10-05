class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;

        int row=grid.size();
        int col=grid[0].size();
        int maxareacount=0;
        
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==1){
                    int currentareacount=findtheareaofisland(grid,r,c);
                    maxareacount=max(maxareacount,currentareacount);
                }
            }
        }
    return maxareacount;
    }
    int findtheareaofisland(vector<vector<int>>& grid, int r, int c){
        int row=grid.size();
        int col=grid[0].size();

        if(r<0 || r>=row || c<0 || c>=col || grid[r][c]==0)
            return 0;

        grid[r][c]=0;
        int area=1;
        area+=findtheareaofisland(grid,r-1,c);//up
        area+=findtheareaofisland(grid,r+1,c);//down
        area+=findtheareaofisland(grid,r,c-1);//left
        area+=findtheareaofisland(grid,r,c+1);//right

        return area;
    }
};
