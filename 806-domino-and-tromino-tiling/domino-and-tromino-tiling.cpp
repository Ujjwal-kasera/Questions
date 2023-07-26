#define mod 1000000007
class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n<0)
            return 0;
        if(n==0 || n==1 )
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=solve(n-1,dp)%mod;
        dp[n]*=2;
        dp[n]%=mod;
        dp[n]+=solve(n-3,dp)%mod;
        dp[n]%=mod;
        // return dp[n]=((2*(numTilings(n-1)%mod))%mod+numTilings(n-3)%mod)%mod;
        return dp[n];
    }
    int numTilings(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};