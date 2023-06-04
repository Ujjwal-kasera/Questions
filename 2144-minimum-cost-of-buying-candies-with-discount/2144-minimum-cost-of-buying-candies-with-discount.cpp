class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int mini=0;
        int buy=cost.size()-1;
        while(buy>=0){
            mini+=cost[buy--];
            if(buy>=0)
                mini+=cost[buy--];
            buy--;
        }
        return mini;
    }
};