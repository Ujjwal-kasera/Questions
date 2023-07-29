class Solution {
public:
    int lenM,lenN;
    int solveMem(vector<vector<int>>&obstacleGrid,int x,int y,vector<vector<int>>&dp){
        if(x>=lenM || y>=lenN)
            return 0;
        if(obstacleGrid[x][y]==1)
            return 0;
        if(x==lenM-1 && y==lenN-1)
            return 1;
        if(dp[x][y]!=-1)
            return dp[x][y];
        // Down
        int ans=0;
        ans+=solveMem(obstacleGrid,x+1,y,dp);

        // Right
        ans+=solveMem(obstacleGrid,x,y+1,dp);

        return dp[x][y]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        lenM=obstacleGrid.size();
        lenN=obstacleGrid[0].size();
        vector<vector<int>>dp(lenM,vector<int>(lenN,-1));
        return solveMem(obstacleGrid,0,0,dp);
    }
};