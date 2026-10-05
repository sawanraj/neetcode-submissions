class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        return 0;

        int islandcount=0;
        int row=grid.size();
        int col=grid[0].size();

        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                //If one land found then find the adjecent land to form island
                if(grid[r][c]=='1'){
                    islandcount++;
                    findisland(grid,r,c);
                }
            }
        }
    return islandcount;
    }
    void findisland(vector<vector<char>>&grid, int r, int c){
        int row=grid.size();
        int col=grid[0].size();

        if(r<0 || r>=row || c<0 || c>=col || grid[r][c] == '0')
            return;

        grid[r][c]='0';
        findisland(grid,r-1,c);//up
        findisland(grid,r+1,c);//Down
        findisland(grid,r,c-1);//left
        findisland(grid,r,c+1);//right
    }
};
