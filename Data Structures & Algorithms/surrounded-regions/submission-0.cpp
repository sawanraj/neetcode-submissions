class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;

        int row=board.size();
        int col=board[0].size();
        //'0' at edage of left and right
        for(int r=0;r<row;r++){
            checksurround(board,r,0); //Left
            checksurround(board,r,col-1); //right
        }
        //'0' at edage of top and bottom
        for(int c=0;c<col;c++){
            checksurround(board,0,c); //top
            checksurround(board,row-1,c); //bottom
        }
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(board[r][c]=='O'){
                    board[r][c]='X';
                }
                else if(board[r][c] =='#'){
                    board[r][c]='O';
                }
            }
        }
    return;
    }
    void checksurround(vector<vector<char>>& board, int r, int c){
        int row=board.size();
        int col=board[0].size();

        if(r<0 || r >=row || c<0 || c>=col || board[r][c]!='O'){
            return ;
        }
        board[r][c]='#';
        checksurround(board,r+1,c);
        checksurround(board,r-1,c);
        checksurround(board,r,c+1);
        checksurround(board,r,c-1);
    }
};
