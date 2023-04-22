class Solution {
public:
    int mod=1e9+7;
    int face;
    int solve(int n, int target,vector<vector<int>>&dp){
        if(target<0)
            return 0;
        if(target==0 && n!=0)
            return 0;
        if(n==0 && target!=0)
            return 0;
        if(n==0 && target==0)
            return 1;
        if(dp[n][target]!=-1)
            return dp[n][target];
        int ans=0;
        for(int i=1;i<=face;i++){
            ans=(ans+solve(n-1,target-i,dp))%mod;
        }
        return dp[n][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        face=k;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,target,dp);
    }
};