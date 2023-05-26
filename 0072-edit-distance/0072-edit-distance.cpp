class Solution {
public:
    int len1,len2;
    int solve(string &word1,string &word2,int i,int j,vector<vector<int>> &dp){
        if(i>=len1)
            return len2-j;
        if(j>=len2)
            return len1-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=1e9;
        if(word1[i]==word2[j])
            ans=solve(word1,word2,i+1,j+1,dp);
        else{
            ans=min(ans,solve(word1,word2,i,j+1,dp)+1);
            ans=min(ans,solve(word1,word2,i+1,j,dp)+1);
            ans=min(ans,solve(word1,word2,i+1,j+1,dp)+1);
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        len1=word1.size();
        len2=word2.size();
        vector<vector<int>> dp(len1,vector<int>(len2,-1));
        return solve(word1,word2,0,0,dp);
    }
};