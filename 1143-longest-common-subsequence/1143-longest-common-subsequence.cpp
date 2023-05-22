class Solution {
public:
    int len1,len2;
    int solveMem(string &text1, string &text2,int i,int j,vector<vector<int>>&dp){
        if(i>=len1 || j>=len2)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(text1[i]==text2[j])
            dp[i][j]=1+solveMem(text1,text2,i+1,j+1,dp);
        else
            dp[i][j]=max(solveMem(text1,text2,i+1,j,dp),solveMem(text1,text2,i,j+1,dp));
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        len1=text1.size();
        len2=text2.size();
        vector<vector<int>> dp(len1,vector<int>(len2,-1));
        return solveMem(text1,text2,0,0,dp);
    }
};