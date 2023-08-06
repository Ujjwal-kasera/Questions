class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(n+1,vector<int>(goal+1,-1));
        return helper(n,goal,k,dp);
    }

    long long helper(int n, int goal, int k, vector<vector<int>>&dp)
    {
        if(n==0 && goal==0) return 1;
        if(n==0 || goal==0) return 0;

        int mod=1e9+7;

        if(dp[n][goal]!=-1) return dp[n][goal];

        long long pick=n*helper(n-1,goal-1,k,dp);
        long long not_pick=helper(n,goal-1,k,dp)*max(n-k,0);
        return dp[n][goal]=(pick+not_pick)%mod;
    }

};