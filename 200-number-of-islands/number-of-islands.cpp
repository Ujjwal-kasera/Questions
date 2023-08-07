class Solution {
public:
    int rowLen,colLen;
    void traverse(vector<vector<char>>&grid,int row,int col){
        if(row<0 || row>=rowLen || col<0 || col>=colLen || grid[row][col]=='0')
            return;
        grid[row][col]='0';
        // Down
        traverse(grid,row+1,col);
        // Up
        traverse(grid,row-1,col);
        // Left
        traverse(grid,row,col-1);
        // Right
        traverse(grid,row,col+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        rowLen=grid.size();
        colLen=grid[0].size();
        for(int row=0;row<rowLen;++row){
            for(int col=0;col<colLen;++col){
                if(grid[row][col]=='1'){
                    res++;
                    traverse(grid,row,col);
                }
            }
        }
        return res;
    }
};