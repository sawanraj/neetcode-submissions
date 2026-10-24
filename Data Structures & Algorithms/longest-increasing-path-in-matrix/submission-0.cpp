class Solution {
    int row;
    int col;
    vector<vector<int>>dp;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row=matrix.size();
        col=matrix[0].size();
        dp.assign(row,vector<int>(col,0));
        int ans=1;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                ans=max(ans,dfs(matrix,r,c));
            }
        }
    return ans;
    }
    int dfs(vector<vector<int>>& matrix,int rw,int cl){
        if(dp[rw][cl]!=0)
            return dp[rw][cl];

        int best=1;
        for(int d=0;d<4;d++){
            int r=rw+dx[d];
            int c=cl+dy[d];

            if(r>=0 && r<row && c>=0 && c<col){
                if(matrix[r][c]>matrix[rw][cl]){
                    int current=1+dfs(matrix,r,c);
                    best=max(best,current);
                }
            }
        }
    return dp[rw][cl]=best;
    }
};
