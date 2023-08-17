class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rowLen=mat.size();
        int colLen=mat[0].size();
        vector<vector<int>> res(rowLen,vector<int>(colLen,1e9));
        for(int row=0;row<rowLen;++row){
            for(int col=0;col<colLen;++col){
                if(mat[row][col]==0)
                    res[row][col]=0;
                else{
                    if(row>0)
                        res[row][col]=min(res[row][col],res[row-1][col]+1);
                    if(col>0)
                        res[row][col]=min(res[row][col],res[row][col-1]+1);
                }
            }
        }
        for(int row=rowLen-1;row>=0;--row){
            for(int col=colLen-1;col>=0;--col){
                if(mat[row][col]==0)
                    res[row][col]=0;
                else{
                    if(row<rowLen-1)
                        res[row][col]=min(res[row][col],res[row+1][col]+1);
                    if(col<colLen-1)
                        res[row][col]=min(res[row][col],res[row][col+1]+1);
                }
            }
        }
        return res;
    }
};