class Solution {
public:
    int len;
    // int solveRec(int index,vector<int>& days, vector<int>& costs){
    //     if(index>=len)
    //         return 0;
    //     int day1=costs[0]+solveRec(index+1,days,costs);
    //     int idx;
    //     for(idx=index;idx<len && days[idx]<days[index]+7;++idx);
    //     int day7=costs[1]+solveRec(idx,days,costs);
    //     for(idx=index;idx<len && days[idx]<days[index]+30;++idx);
    //     int day30=costs[2]+solveRec(idx,days,costs);
    //     return min({day1,day7,day30});
    // }

    // int solveMem(int index,vector<int>& days, vector<int>& costs,vector<int>&dp){
    //     if(index>=len)
    //         return 0;
    //     if(dp[index]!=-1)
    //         return dp[index];
    //     int day1=costs[0]+solveMem(index+1,days,costs,dp);
    //     int idx;
    //     for(idx=index;idx<len && days[idx]<days[index]+7;++idx);
    //     int day7=costs[1]+solveMem(idx,days,costs,dp);
    //     for(idx=index;idx<len && days[idx]<days[index]+30;++idx);
    //     int day30=costs[2]+solveMem(idx,days,costs,dp);
    //     return dp[index]=min({day1,day7,day30});
    // }

    int solveTab(vector<int>& days, vector<int>& costs){
        vector<int> dp(len+1,0);
        for(int index=len-1;index>=0;--index){
            int day1=costs[0]+dp[index+1];
            int idx;
            for(idx=index;idx<len && days[idx]<days[index]+7;++idx);
            int day7=costs[1]+dp[idx];
            for(idx=index;idx<len && days[idx]<days[index]+30;++idx);
            int day30=costs[2]+dp[idx];
            dp[index]=min({day1,day7,day30});
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        len=days.size();
        return solveTab(days,costs);
        // vector<int> dp(len,-1);
        // return solveMem(0,days,costs,dp);
        // return solveRec(0,days,costs);
    }
};