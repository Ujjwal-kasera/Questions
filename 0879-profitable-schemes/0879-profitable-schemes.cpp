class Solution {
public:
    int len;
    int mod=1e9+7;
    // int target;
    int solve(int n, int index, int Profit, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>&dp){
        if(index==len)
            return (Profit<=0);
        int incl=0;
        if(dp[index][n][Profit]!=-1)
            return dp[index][n][Profit];
        if(n-group[index]>=0){
            int temp=Profit-profit[index];
            if(temp<0)
                temp=0;
            incl=solve(n-group[index],index+1,temp,group,profit,dp);
        }
        int excl=solve(n,index+1,Profit,group,profit,dp);
        dp[index][n][Profit]=(incl+excl)%mod;
        return dp[index][n][Profit];
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        len=group.size();
        // target=minProfit;
        vector<vector<vector<int>>>dp(len+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return solve(n,0,minProfit,group,profit,dp);
    }
};