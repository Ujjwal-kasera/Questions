class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size()-1,col=0,col_len=matrix[0].size();
        while(row>=0 && col<col_len){
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                row--;
            else 
                col++;
        }
        return false;
    }
};