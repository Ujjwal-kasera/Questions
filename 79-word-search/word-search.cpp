class Solution {
public:
    int len,rowLen,colLen;
    vector<vector<bool>> vis;
    bool isVaid(vector<vector<char>> &board,string &word,int row,int col,int idx){
        if(row>=0 && row<rowLen && col>=0 && col<colLen && board[row][col]==word[idx] && vis[row][col]==0)
            return 1;
        return 0;
    }
    bool solve(vector<vector<char>>&board,string &word,int row, int col, int idx){
        if(idx==len-1)
            return 1;

        if(row<0 || row>=rowLen || col<0 || col>=colLen)
            return 0;

        bool ans=false;
        vis[row][col]=1;

        // Up
        if(isVaid(board,word,row-1,col,idx+1))
            ans|=solve(board,word,row-1,col,idx+1);

        // Down
        if(isVaid(board,word,row+1,col,idx+1))
            ans|=solve(board,word,row+1,col,idx+1);

        // Left
        if(isVaid(board,word,row,col-1,idx+1))
            ans|=solve(board,word,row,col-1,idx+1);

        // Right
        if(isVaid(board,word,row,col+1,idx+1))
            ans|=solve(board,word,row,col+1,idx+1);

        vis[row][col]=0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        len=word.size();
        rowLen=board.size();
        colLen=board[0].size();
        vis.assign(rowLen,vector<bool>(colLen,0));
        bool ans=false;
        for(int row=0;row<rowLen;++row){
            for(int col=0;col<colLen;++col){
                if(board[row][col]==word[0]){
                    ans=solve(board,word,row,col,0);
                    if(ans==true)
                        return ans;
                }
            }
        }
        return ans;
    }
};