class Solution {
public:
    int len;
    int solveMem(vector<int>& prices,int index,int buy,vector<vector<int>> &dp){
        if(index>=len || buy>=4){
            return 0;
        }
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        int profit1,profit2;
        if(!(buy&1)){
            profit1=-prices[index]+solveMem(prices,index+1,buy+1,dp);
            profit2=solveMem(prices,index+1,buy,dp);
        }
        else{
            profit1=prices[index]+solveMem(prices,index+1,buy+1,dp);
            profit2=solveMem(prices,index+1,buy,dp);
        }
        return dp[index][buy]=max(profit1,profit2);
    }
    int maxProfit(vector<int>& prices) {
        len=prices.size();
        vector<vector<int>> dp(len,vector<int>(4,-1));
        return solveMem(prices,0,0,dp);
    }
};