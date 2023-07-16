class Solution {
public:
    int bisectRight(vector<vector<int>>&events, int target) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }   
    int maxValue(vector<vector<int>>& events, int k) {
        int len=events.size();
        vector<vector<int>> dp(len+1,vector<int>(k+1,0));
        sort(events.begin(),events.end());
        vector<int> next(len,len);
        for(int i=0;i<len;i++){
            next[i]=bisectRight(events,events[i][1]);
            // next[i]=upper_bound(events.begin()+i,events.end(),vector<int>{events[i][1]+1,0,0})-events.begin();
        }
        
        for(int i=len-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                int take=dp[next[i]][j-1]+events[i][2];
                int skip=dp[i+1][j];
                dp[i][j]=max(take,skip);
            }
        }
        return dp[0][k];
    }
    // int solve(vector<vector<int>>& events,int k,int index,int prev,vector<vector<int>>&dp){
    //     if(k==0 || index==events.size())
    //         return 0;
    //     if(events[index][0]<=prev)
    //         return solve(events,k,index+1,prev,dp);
    //     if(dp[index][k]!=-1)
    //         return dp[index][k];
    //     int take=0,skip=0;
    //     take=solve(events,k-1,index+1,events[index][1],dp)+events[index][2];
    //     skip=solve(events,k,index+1,prev,dp);
    //     return dp[index][k]=max(take,skip);
    // }
    // int maxValue(vector<vector<int>>& events, int k) {
    //     vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
    //     sort(events.begin(),events.end());
    //     return solve(events,k,0,-1,dp);
    // }
};