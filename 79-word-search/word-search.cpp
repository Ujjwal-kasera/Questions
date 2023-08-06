class Solution {
public:
    int len,rowLen,colLen;
    string word;
    vector<vector<bool>> vis;
    vector<vector<char>> board;
    
    bool isVaid(int row,int col,int idx){
        if(row>=0 && row<rowLen && col>=0 && col<colLen && board[row][col]==word[idx] && vis[row][col]==0)
            return 1;
        return 0;
    }
    bool solve(int row, int col, int idx){
        if(idx==len-1)
            return 1;

        if(row<0 || row>=rowLen || col<0 || col>=colLen)
            return 0;

        bool ans=false;
        vis[row][col]=1;

        // Up
        if(isVaid(row-1,col,idx+1))
            ans|=solve(row-1,col,idx+1);

        // Down
        if(isVaid(row+1,col,idx+1))
            ans|=solve(row+1,col,idx+1);

        // Left
        if(isVaid(row,col-1,idx+1))
            ans|=solve(row,col-1,idx+1);

        // Right
        if(isVaid(row,col+1,idx+1))
            ans|=solve(row,col+1,idx+1);

        vis[row][col]=0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        len=word.size();
        rowLen=board.size();
        colLen=board[0].size();
        this->word=word;
        this->board=board;
        vis.assign(rowLen,vector<bool>(colLen,0));
        for(int row=0;row<rowLen;++row){
            for(int col=0;col<colLen;++col){
                if(board[row][col]==word[0]){
                    if(solve(row,col,0))
                        return true;
                }
            }
        }
        return false;
    }
};