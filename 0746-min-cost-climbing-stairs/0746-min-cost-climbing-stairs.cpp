class Solution {
    int funRec(vector<int>&cost,int len,vector<int>&dp){
        if(len==1 || len==0)
            return cost[len];
        if(dp[len]!=-1)
            return dp[len];
        dp[len]=min(funRec(cost,len-2,dp),funRec(cost,len-1,dp))+cost[len];
        return dp[len];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();
        vector<int>dp(len+1,-1);
        int c_n=funRec(cost,len-1,dp);
        int c_n1=funRec(cost,len-2,dp);
        if(c_n<c_n1)
            return c_n;
        return c_n1;
    }
};