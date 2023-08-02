class Solution {
public:
    int len;
    int solveMem(vector<int>&obstacles,int currpos,int currlane,vector<vector<int>> &dp){
        if(currpos==len-1)
            return 0;
        if(dp[currlane][currpos]!=-1)
            return dp[currlane][currpos];
        int ans=1e9;
        if(obstacles[currpos+1]!=currlane)
            ans=solveMem(obstacles,currpos+1,currlane,dp);
        else{
            for(int i=1;i<4;i++){
                if(currlane!=i && obstacles[currpos]!=i)
                    ans=min(ans,solveMem(obstacles,currpos+1,i,dp)+1);
            }
        }
        return dp[currlane][currpos]=ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        len=obstacles.size();
        vector<vector<int>> dp(4,vector<int>(len,-1));
        return solveMem(obstacles,0,2,dp);
    }
};