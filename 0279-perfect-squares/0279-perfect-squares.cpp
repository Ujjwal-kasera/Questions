class Solution {
    // int solveMem(int n,vector<int>&dp){
    //     if(n==0)
    //         return 0;
    //     if(n<0)
    //         return INT_MAX;
    //     if(dp[n]!=-1)
    //         return dp[n];
    //     int sqr=sqrt(n);
    //     int mini=INT_MAX;
    //     int ans;
    //     for(int i=1;i<=n;i++){
    //         ans=solveMem(n-(i*i),dp);
    //         if(ans!=INT_MAX)
    //             mini=min(mini,ans+1);
    //     }
    //     dp[n]=mini;
    //     return dp[n];
    // }
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        int sqr,idx;
        for(int i=1;i<=n;i++){
            sqr=sqrt(i);
            for(int j=1;j<=sqr;j++){
                idx=i-(j*j);
                if(idx>=0 && dp[idx]!=INT_MAX)
                    dp[i]=min(dp[i],dp[idx]+1);
            }
        }
        return dp[n];
    }
};