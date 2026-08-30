class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) 
            return false;
        
        int m=matrix.size();
        int n=matrix[0].size();
        int r=0;
        int c=n-1;

        while(r<m && c>=0){
            int val=matrix[r][c];

            if(val == target)
            {
                return true;
            }
            else if (val >target){
                c--;
            }
            else{
                r++;
            }
        }
    return false;
    }
};
