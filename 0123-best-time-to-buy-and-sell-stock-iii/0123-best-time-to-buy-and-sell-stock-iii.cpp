class Solution {
public:
    int len;
    
    //Memoziation
    // int solveMem(vector<int>& prices,int index,int buy,vector<vector<int>> &dp){
    //     if(index>=len || buy>=4){
    //         return 0;
    //     }
    //     if(dp[index][buy]!=-1)
    //         return dp[index][buy];
    //     int profit1,profit2;
    //     if(!(buy&1)){
    //         profit1=-prices[index]+solveMem(prices,index+1,buy+1,dp);
    //         profit2=solveMem(prices,index+1,buy,dp);
    //     }
    //     else{
    //         profit1=prices[index]+solveMem(prices,index+1,buy+1,dp);
    //         profit2=solveMem(prices,index+1,buy,dp);
    //     }
    //     return dp[index][buy]=max(profit1,profit2);
    // }
    
    // Tabulation
    int solveTab(vector<int> &prices){
        vector<vector<int>>dp(len+1,vector<int>(5,0));
        for(int index=len-1;index>=0;index--){
            for(int buy=3;buy>=0;buy--){
                int profit1,profit2;
                if(!(buy&1)){
                    profit1=-prices[index]+dp[index+1][buy+1];
                    profit2=dp[index+1][buy];
                }
                else{
                    profit1=prices[index]+dp[index+1][buy+1];
                    profit2=dp[index+1][buy];
                }
                dp[index][buy]=max(profit1,profit2);
            }
        }
        return dp[0][0];
    }
    
    // Space Optimisation
    // int solveSpace()
    int maxProfit(vector<int>& prices) {
        len=prices.size();
        // vector<vector<int>> dp(len,vector<int>(4,-1));
        // return solveMem(prices,0,0,dp);
        return solveTab(prices);
    }
};