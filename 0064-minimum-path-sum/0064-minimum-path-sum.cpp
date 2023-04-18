class Solution {
public:
    int row;
    int col;
    int solve(vector<vector<int>>& grid, int r, int c, vector<vector<int>> &dp){
        if(r==row-1 && c==col-1)
            return grid[r][c];
        if(r>=row || c>=col)
            return INT_MAX;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int down=solve(grid,r+1,c,dp);
        int right=solve(grid,r,c+1,dp);
        dp[r][c]=(min(right,down)+grid[r][c]);
        return dp[r][c];
    }
    int minPathSum(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return solve(grid,0,0,dp);
    }
};