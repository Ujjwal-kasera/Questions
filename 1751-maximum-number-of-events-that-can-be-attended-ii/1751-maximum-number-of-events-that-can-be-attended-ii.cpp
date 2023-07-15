class Solution {
public:
    int solve(vector<vector<int>>& events,int k,int index,int prev,vector<vector<int>>&dp){
        if(k==0 || index==events.size())
            return 0;
        if(events[index][0]<=prev)
            return solve(events,k,index+1,prev,dp);
        if(dp[index][k]!=-1)
            return dp[index][k];
        int take=0,skip=0;
        take=solve(events,k-1,index+1,events[index][1],dp)+events[index][2];
        skip=solve(events,k,index+1,prev,dp);
        return dp[index][k]=max(take,skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        return solve(events,k,0,-1,dp);
    }
};