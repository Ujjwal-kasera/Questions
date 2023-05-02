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
};