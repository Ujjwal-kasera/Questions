class Solution {
public:
    int len;
    unordered_map<int,int> stone;
    int solveMem(vector<int>&stones,int idx,int prevMove,vector<vector<int>>&dp){
        if(idx==len-1){
            return 1;
        }
        if(dp[idx][prevMove]!=-1)
            return dp[idx][prevMove];
        int ans=0;
        if((prevMove-1)>0 && stone.count(stones[idx]+prevMove-1))
            ans=ans||solveMem(stones,stone[stones[idx]+prevMove-1],prevMove-1,dp);

        if((prevMove)>0 && stone.count(stones[idx]+prevMove))
            ans=ans||solveMem(stones,stone[stones[idx]+prevMove],prevMove,dp);

        if((prevMove+1)>0 && stone.count(stones[idx]+prevMove+1))
            ans=ans||solveMem(stones,stone[stones[idx]+prevMove+1],prevMove+1,dp);

        return dp[idx][prevMove]=ans;
    }
    bool canCross(vector<int>& stones) {
        len=stones.size();
        for(int i=0;i<len;i++)
            stone[stones[i]]=i;
        vector<vector<int>> dp(len+1,vector<int>(len+1,-1));
        return solveMem(stones,0,0,dp);
    }
};