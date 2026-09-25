class Solution {
public:
    vector<vector<string>>result;
    vector<vector<string>> solveNQueens(int n) {
       //intialize an empty board of size of nxn filled with '.'
        vector<string>board(n,string(n,'.'));
        backtrack(board,0,n);        
        return result;
    }
    void backtrack(vector<string>&board,int row, int n){
        if(row==n){
            result.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(helperqueen(board,n,row,col)){
                board[row][col]='Q'; //place the queen
                backtrack(board,row+1,n); //Move to next row
                board[row][col]='.'; //Backtrack and remove Queen
            }
        }
    }
    bool helperqueen(vector<string>&board,int &n,int r,int c){
         for(int k=0;k<r;k++){
            if(board[k][c] == 'Q')
            return false;
         }
         //Check top left diagonal
         int i=r-1;
         int j=c-1;
         while(i>=0 && j>=0){
            if(board[i][j]=='Q')
            return false;
            i--;j--;
         }
         //check top right diagonal
         i=r-1;
         j=c+1;
         while(i>=0 && j<n){
            if(board[i][j]=='Q')
            return false;

            i--;j++;
         }
        return true;
    }
};
