class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();

        //loop through every single cell in the grid to find the starting point.
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                //Traverse all horizental and vertical match
                if(matchchar(board,word,i,j,0)){return true;}
            }
        }
    return false;
    }
    bool matchchar(vector<vector<char>>& board, string &word, int r,int c,int idx){
        if(idx == word.length()){
            return true;
        }
        //Check boundary and current char matched ?
        if(r<0 || r >=board.size() || c<0 || c>=board[0].size() || board[r][c]!=word[idx] ){
            return false;
        }
        //Store current char from grid and mark visited by #
        char ch=board[r][c];
        board[r][c]='#';
        //now same search for char left(r-1),right(r+1),up(c-1) and down(c+1)
        bool found=matchchar(board,word,r+1,c,idx+1) || 
                   matchchar(board,word,r-1,c,idx+1) || 
                   matchchar(board,word,r,c+1,idx+1) || 
                   matchchar(board,word,r,c-1,idx+1);

        board[r][c]=ch;//back store same char

        return found;
    }
};
