class Solution {
public:
    int len;
    // int solveRec(vector<int>&coins, int amount,int index){
    //     if(amount==0)
    //         return 1;
    //     if(index>=len)
    //         return 0;
    //     int ans=0;
    //     if(amount>=coins[index])
    //         ans+=solveRec(coins,amount-coins[index],index);
    //     ans+=solveRec(coins,amount,index+1);
    //     return ans;
    // }
    int solveMem(vector<int>&coins, int amount,int index,vector<vector<int>> &dp){
        if(amount==0)
            return 1;
        if(index>=len)
            return 0;
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int ans=0;
        if(amount>=coins[index])
            ans+=solveMem(coins,amount-coins[index],index,dp);
        ans+=solveMem(coins,amount,index+1,dp);
        return dp[index][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
        len=coins.size();
        vector<vector<int>> dp(len,vector<int>(amount+1,-1));
        return solveMem(coins,amount,0,dp);
        // return solveRec(coins,amount,0);
    }
};