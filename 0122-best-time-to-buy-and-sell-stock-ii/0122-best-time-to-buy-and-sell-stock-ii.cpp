class Solution {
public:
    /*
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int profit=0;
        int buy=prices[0];
        for(int i=1;i<len;i++){
            if(prices[i]>buy){
                profit+=(prices[i]-buy);
                buy=prices[i];
            }
            else
                buy=min(buy,prices[i]);
        }
        return profit;
    }
    */
    /*
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int profit=0;
        int diff=0;
        for(int i=1;i<len;i++){
            diff=prices[i]-prices[i-1];
            if(diff>0)
                profit+=prices[i]-prices[i-1];
        }
        return profit;
    }
    */
    //hm isme har ek value ek lie bool leke chl rhe ke kya hm use krid skte h ya nhi
    
    // Memoziation
    int len;
    // int solveMem(vector<int>& prices,bool buy,int index,vector<vector<int>> &dp){
    //     if(index>=len){
    //         return 0;
    //     }
    //     if(dp[index][buy]!=-1)
    //         return dp[index][buy];
    //     int profit=0;
    //     if(buy){
    //         int profit1=-prices[index]+solveMem(prices,0,index+1,dp);
    //         int profit2=solveMem(prices,buy,index+1,dp);
    //         profit=max(profit1,profit2);
    //     }
    //     else{
    //         int profit1=prices[index]+solveMem(prices,1,index+1,dp);
    //         int profit2=solveMem(prices,buy,index+1,dp);
    //         profit=max(profit1,profit2);
    //     }
    //     return dp[index][buy]=profit;
    // }
     
    // Tabulation
    // int solveTab(vector<int>&prices){
    //     int len=prices.size();
    //     vector<vector<int>> dp(len+1,vector<int>(2,0));
    //     for(int index=len-1;index>=0;index--){
    //         for(int buy=0;buy<2;buy++){
    //             int profit1,profit2;
    //             if(buy){
    //                 profit1=dp[index+1][0]-prices[index];
    //                 profit2=dp[index+1][1];
    //             }
    //             else{
    //                 profit1=prices[index]+dp[index+1][1];
    //                 profit2=dp[index+1][0];
    //             }
    //             dp[index][buy]=max(profit1,profit2);
    //         }
    //     }
    //     return dp[0][1];
    // }
    
    //Space Optimised
    int solveSpace(vector<int> &prices){
        vector<int> curr(2,0);
        vector<int> next(2,0);
        for(int index=len-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                int profit1,profit2;
                if(buy){
                    profit1=next[0]-prices[index];
                    profit2=next[1];
                }
                else{
                    profit1=prices[index]+next[1];
                    profit2=next[0];
                }
                curr[buy]=max(profit1,profit2);
            }
            next=curr;
        }
        return curr[1];
    }
    int maxProfit(vector<int>& prices) {
        len=prices.size();
        // vector<vector<int>> dp(len,vector<int>(2,-1));
        // return solveMem(prices,1,0,dp);
        // return solveTab(prices);
        return solveSpace(prices);
    }
    /*
    // hm isme buy count ko maintain kr rhe agr to count even rha to hm buy krege
    // wrna agr odd rha to hm sell krege..
    // pr ye wla soln submit nhi ho rha kyuki isme O(n2) space complexity lgega jo ki
    // last test case pass nhi kr pa rha
    int len;
    int solve(vector<int>& prices,int buy,int index,vector<vector<int>> &dp){
        if(index>=len){
            return 0;
        }
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        int profit1,profit2;
        if(!(buy&1)){
            profit1=-prices[index]+solve(prices,buy+1,index+1,dp);
            profit2=solve(prices,buy,index+1,dp);
        }
        else{
            profit1=prices[index]+solve(prices,buy+1,index+1,dp);
            profit2=solve(prices,buy,index+1,dp);
        }
        return dp[index][buy]=max(profit1,profit2);
    }
    int maxProfit(vector<int>& prices) {
        len=prices.size();
        vector<vector<int>> dp(len,vector<int>(len,-1));
        return solve(prices,0,0,dp);
    }
    */
};