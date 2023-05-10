class Solution {
public:
    int len;
    //Memoziation
    // int solveMem(vector<int>& prices,int index,bool buy,vector<vector<int>> &dp){
    //     if(index>=len){
    //         return 0;
    //     }
    //     if(dp[index][buy]!=-1)
    //         return dp[index][buy];
    //     int profit1,profit2;
    //     if(buy){
    //         profit1=-prices[index]+solveMem(prices,index+1,0,dp);
    //         profit2=solveMem(prices,index+1,buy,dp);
    //     }
    //     else{
    //         profit1=prices[index]+solveMem(prices,index+2,1,dp);
    //         profit2=solveMem(prices,index+1,buy,dp);
    //     }
    //     return dp[index][buy]=max(profit1,profit2);
    // }
    
    // Tabulation
    int solveTab(vector<int> &prices){
        vector<vector<int>>dp(len+2,vector<int>(2,0));
        for(int index=len-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                int profit1,profit2;
                if(buy){
                    profit1=-prices[index]+dp[index+1][0];
                    profit2=dp[index+1][buy];
                }
                else{
                    profit1=prices[index]+dp[index+2][1];
                    profit2=dp[index+1][buy];
                }
                dp[index][buy]=max(profit1,profit2);
            }
        }
        return dp[0][1];
    }
    
    // Space Optimisation
    // int solveSpace(vector<int> &prices){
    //     vector<int>curr(2,0);
    //     vector<int> next(2,0);
    //     for(int index=len-1;index>=0;index--){
    //         for(int buy=1;buy>=0;buy--){
    //             int profit1,profit2;
    //             if(buy){
    //                 profit1=-prices[index]+next[0];
    //                 profit2=next[buy];
    //             }
    //             else{
    //                 profit1=prices[index]+next[1]-fees;
    //                 profit2=next[buy];
    //             }
    //             curr[buy]=max(profit1,profit2);
    //         }
    //         next=curr;
    //     }
    //     return curr[1];
    // }
    
    int maxProfit(vector<int>& prices) {
        len=prices.size();
        // vector<vector<int>> dp(len,vector<int>(2,-1));
        // return solveMem(prices,0,1,dp);
        return solveTab(prices);
        // return solveSpace(prices);
    }
};