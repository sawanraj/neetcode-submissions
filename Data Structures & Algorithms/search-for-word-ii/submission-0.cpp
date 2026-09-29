struct TrieNode{
    TrieNode* children[26]={nullptr};
    string word="";
};
class Solution {
public:
    //Helper function to insert a word into the Trie
    void insertword(TrieNode* root,const string& word){
        TrieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]){
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];
        }
        node->word=word;
    }
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& result){
        char ch=board[r][c];
        if(ch =='#')
            return;
        int idx=ch-'a';

        //Base cases: char not in Trie or cell already visited('#')
        if(ch =='#'|| !node->children[idx])
            return;

        node=node->children[idx];
        //if we found a valid word, add it to the result
        if(!node->word.empty()){
            result.push_back(node->word);
            node->word="";//Avoid duplicate entries for the same word
        }
        //mark the current cell as visited
        board[r][c]='#';
        //Explore all 4 neighbor direction (up,down,left,right)
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};

        for(int i=0;i<4;i++){
            int newrow=r+drow[i];
            int newcol=c+dcol[i];

            //Check boundry condition
            if(newrow >=0 && newrow<board.size() && newcol >=0 && newcol <board[0].size()){
                dfs(board,newrow,newcol,node,result);
            }
        }
        //backtrack: restore the cell's original character
        board[r][c]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root=new TrieNode();
        //1 build the Trie
        for(const string& word:words){
            insertword(root,word);
        }
        vector<string>result;
        int rows=board.size();
        int cols=board[0].size();

        for(int r=0;r<rows;++r){
            for(int c=0;c<cols;++c){
                dfs(board,r,c,root,result);
            }
        }
    return result;
    }
};
