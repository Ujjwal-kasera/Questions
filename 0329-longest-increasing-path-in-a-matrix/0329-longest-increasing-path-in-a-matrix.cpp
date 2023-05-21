class Solution {
public:
    int row,col;
    int solve(vector<vector<int>>& matrix,int r,int c,vector<vector<int>> &dp){
        if(r>=row || c>=col)
            return 0;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int ans=0;
        if(r+1<row && matrix[r+1][c]>matrix[r][c])
            ans=max(ans,solve(matrix,r+1,c,dp));
        if(r-1>=0 && matrix[r-1][c]>matrix[r][c])
            ans=max(ans,solve(matrix,r-1,c,dp));
        if(c+1<col && matrix[r][c+1]>matrix[r][c])
            ans=max(ans,solve(matrix,r,c+1,dp));
        if(c-1>=0 && matrix[r][c-1]>matrix[r][c])
            ans=max(ans,solve(matrix,r,c-1,dp));
        return dp[r][c]=ans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row=matrix.size();
        col=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(row,vector<int>(col,-1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans=max(ans,solve(matrix,i,j,dp));
            }
        }
        return ans;
    }
};