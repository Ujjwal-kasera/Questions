class Solution {
    /*
    int solveRec(vector<int>&coins, int amount){
        if(amount==0)
            return 0;
        if(amount<1)
            return INT_MAX;
        int mini=INT_MAX;
        int ans;
        for(int i=0;i<coins.size();i++){
            ans=solveRec(coins,amount-coins[i]);
            if(ans !=INT_MAX)
                mini=min(mini,1+ans);
        }
        return mini;
    }
    */
    
    // int solveMem(vector<int>&coins, int amount,vector<int> &dp){
    //     if(amount==0)
    //         return 0;
    //     if(amount<1)
    //         return INT_MAX;
    //     if(dp[amount]!=-1)
    //         return dp[amount];
    //     int mini=INT_MAX;
    //     int ans;
    //     for(int i=0;i<coins.size();i++){
    //         ans=solveMem(coins,amount-coins[i],dp);
    //         if(ans !=INT_MAX)
    //             mini=min(mini,1+ans);
    //     }
    //     dp[amount]=mini;
    //     return dp[amount];
    // }
public:
    // int coinChange(vector<int>& coins, int amount) {
    //     // int ans=solveRec(coins,amount);
    //     vector<int>dp(amount+1,-1);
    //     int ans=solveMem(coins,amount,dp);
    //     if(ans==INT_MAX)
    //         return -1;
    //     return ans;
    // }
    
    int coinChange(vector<int>& coins, int amount){
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
};