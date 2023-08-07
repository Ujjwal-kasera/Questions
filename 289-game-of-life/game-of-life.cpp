class Solution {
public:
    int rowLen,colLen;
    bool isLive(vector<vector<int>>&board,int row, int col){
        if(row>=0 && row<rowLen && col>=0 && col<colLen && board[row][col]==1)
            return 1;
        return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int cnt;
        rowLen=board.size();
        colLen=board[0].size();
        vector<vector<bool>> vec(rowLen,vector<bool>(colLen,0));
        for(int row=0;row<rowLen;++row){
            for(int col=0;col<colLen;++col){
                cnt=0;
                if(isLive(board,row-1,col))
                    cnt++;
                if(isLive(board,row+1,col))
                    cnt++;
                if(isLive(board,row,col-1))
                    cnt++;
                if(isLive(board,row,col+1))
                    cnt++;
                if(isLive(board,row-1,col-1))
                    cnt++;
                if(isLive(board,row-1,col+1))
                    cnt++;
                if(isLive(board,row+1,col-1))
                    cnt++;
                if(isLive(board,row+1,col+1))
                    cnt++;

                if(board[row][col]==0 && cnt==3)
                    vec[row][col]=1;
                else if(board[row][col]==1 && cnt>1 && cnt<4)
                    vec[row][col]=1;
            }
        }
        for(int row=0;row<rowLen;++row){
            for(int col=0;col<colLen;++col){
                board[row][col]=vec[row][col];
            }
        }
    }
};