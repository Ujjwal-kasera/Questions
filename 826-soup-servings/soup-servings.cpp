class Solution {
public:
    double solveRec(int A,int B,vector<vector<double>>&dp){
        if(A<=0 && B<=0)
            return 0.5;
        if(A<=0 && B>0)
            return 1;
        else if(A>0 && B<=0)
            return 0;
        if(dp[A][B]!=-1.0)
            return dp[A][B];
        double ans=0;
        ans+=solveRec(A-100,B,dp);
        ans+=solveRec(A-75,B-25,dp);
        ans+=solveRec(A-50,B-50,dp);
        ans+=solveRec(A-25,B-75,dp);
        return dp[A][B]=ans/4;
    }
    double soupServings(int n) {
        if(n>4300)
            return 1;
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1.0));
        return solveRec(n,n,dp);
    }
};