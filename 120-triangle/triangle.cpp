class Solution {
public:
    int rowLen;
    int solveMem(vector<vector<int>>&triangle,int row,int idx,vector<vector<int>> &dp){
        if(row==rowLen){
            return 0;
        }
        if(dp[row][idx]!=-1)
            return dp[row][idx];
        int curr=solveMem(triangle,row+1,idx,dp);
        int next=solveMem(triangle,row+1,idx+1,dp);
        return dp[row][idx]=min(curr,next)+triangle[row][idx];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        rowLen=triangle.size();
        vector<vector<int>> dp(rowLen,vector<int>(triangle[rowLen-1].size(),-1));
        return solveMem(triangle,0,0,dp);
    }
};