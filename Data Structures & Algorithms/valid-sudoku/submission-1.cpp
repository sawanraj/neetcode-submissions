class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>seen;/*to check duplicate*/
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                /*define char of string*/
                char num=board[i][j];
                if(num=='.')
                continue;
                /*create string identifiers from all 3 constarint(row, cloumn, box(3x3))*/
                string row_check=string(1,num)+"in_row"+to_string(i);
                string col_check=string(1,num)+"in_col"+to_string(j);
                string box_check=string(1,num)+"in_box"+to_string(i/3)+to_string(j/3);

                if(seen.count(row_check)|| seen.count(col_check) || seen.count(box_check))
                return false;

                seen.insert(row_check);
                seen.insert(col_check);
                seen.insert(box_check);

            }
        }
    return true;
    }
};
