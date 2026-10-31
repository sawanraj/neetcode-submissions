class Solution {
    int row;
    int col;
    int direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        int minute=0;
        int fresh=0;
        queue<pair<int,int>>qp;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==2){
                    qp.push({r,c});
                }
                if(grid[r][c]==1){
                    fresh++;
                }
            }
        }
        while(!qp.empty() && fresh >0){
            int size=qp.size();
            while(size--){
                auto[r,c]=qp.front();
                qp.pop();
                for (auto &dirc:direction){
                    int nr=r+dirc[0];
                    int nc=c+dirc[1];
                    if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        qp.push({nr,nc});
                    }
                }
            }
            minute++;
        }
    return fresh==0?minute:-1;
    }
};
