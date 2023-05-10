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
    int len;
    int solve(vector<int>& prices,bool buy,int index,vector<vector<int>> &dp){
        if(index>=len){
            return 0;
        }
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        int profit1,profit2;
        if(buy){
            profit1=-prices[index]+solve(prices,0,index+1,dp);
            profit2=solve(prices,buy,index+1,dp);
        }
        else{
            profit1=prices[index]+solve(prices,1,index+1,dp);
            profit2=solve(prices,buy,index+1,dp);
        }
        return dp[index][buy]=max(profit1,profit2);
    }
    int maxProfit(vector<int>& prices) {
        len=prices.size();
        vector<vector<int>> dp(len,vector<int>(2,-1));
        return solve(prices,1,0,dp);
    }
};