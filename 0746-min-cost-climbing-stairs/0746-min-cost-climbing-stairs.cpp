class Solution {
    // int funRec(vector<int>&cost,int len){
    //     if(len==1 || len==0)
    //         return cost[len];
    //     int c=min(funRec(cost,len-2),funRec(cost,len-1))+cost[len];
    //     return c;
    // }
    
    // int funMem(vector<int>&cost,int len,vector<int>&dp){
    //     if(len==1 || len==0)
    //         return cost[len];
    //     if(dp[len]!=-1)
    //         return dp[len];
    //     dp[len]=min(funMem(cost,len-2,dp),funMem(cost,len-1,dp))+cost[len];
    //     return dp[len];
    // }
    
public:
    // Recursion
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int len=cost.size();
    //     int c_n=funRec(cost,len-1);
    //     int c_n1funRec(cost,len-2);
    //     if(c_n<c_n1)
    //         return c_n;
    //     return c_n1;
    // }
    
    // Memoziation
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int len=cost.size();
    //     vector<int>dp(len+1,-1);
    //     int c_n=funRec(cost,len-1,dp);
    //     int c_n1=funRec(cost,len-2,dp);
    //     if(c_n<c_n1)
    //         return c_n;
    //     return c_n1;
    // }
    
    // Tabulation
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();
        vector<int>dp(len);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<len;i++)
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        return dp[len-1]<dp[len-2]?dp[len-1]:dp[len-2];
    }
    
};