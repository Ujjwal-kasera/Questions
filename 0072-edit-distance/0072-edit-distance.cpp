class Solution {
public:
    int len1,len2;
    // Recursion
    // int solve(string &word1,string &word2,int i,int j){
    //     if(i>=len1)
    //         return len2-j;
    //     if(j>=len2)
    //         return len1-i;
    //     int ans=1e9;
    //     if(word1[i]==word2[j])
    //         ans=solve(word1,word2,i+1,j+1);
    //     else{
    //         ans=min(ans,solve(word1,word2,i,j+1)+1);
    //         ans=min(ans,solve(word1,word2,i+1,j)+1);
    //         ans=min(ans,solve(word1,word2,i+1,j+1)+1);
    //     }
    //     return ans;
    // }
    // Memoziation
    // int solveMem(string &word1,string &word2,int i,int j,vector<vector<int>> &dp){
    //     if(i>=len1)
    //         return len2-j;
    //     if(j>=len2)
    //         return len1-i;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int ans=1e9;
    //     if(word1[i]==word2[j])
    //         ans=solveMem(word1,word2,i+1,j+1,dp);
    //     else{
    //         ans=min(ans,solveMem(word1,word2,i,j+1,dp)+1);
    //         ans=min(ans,solveMem(word1,word2,i+1,j,dp)+1);
    //         ans=min(ans,solveMem(word1,word2,i+1,j+1,dp)+1);
    //     }
    //     return dp[i][j]=ans;
    // }
    
    // Tabulation
    // int solveTab(string word1,string word2){
    //     vector<vector<int>> dp(len1+1,vector<int>(len2+1));
    //     for(int i=0;i<len1;i++)
    //         dp[i][len2]=len1-i;
    //     for(int i=0;i<len2;i++)
    //         dp[len1][i]=len2-i;
    //     for(int i=len1-1;i>=0;i--){
    //         for(int j=len2-1;j>=0;j--){
    //             int ans=1e9;
    //             if(word1[i]==word2[j])
    //                 ans=dp[i+1][j+1];
    //             else{
    //                 ans=min(ans,dp[i][j+1]+1);
    //                 ans=min(ans,dp[i+1][j]+1);
    //                 ans=min(ans,dp[i+1][j+1]+1);
    //             }
    //             dp[i][j]=ans;
    //         }
    //     }
    //     return dp[0][0];
    // }
    int solveOptimised(string word1,string word2){
        vector<int> curr(len2+1,0);
        vector<int> next(len2+1,0);
        for(int i=0;i<=len2;i++)
            next[i]=len2-i;
        for(int i=len1-1;i>=0;i--){
            for(int j=len2-1;j>=0;j--){
                curr[len2]=len1-i;
                int ans=1e9;
                if(word1[i]==word2[j])
                    ans=next[j+1];
                else{
                    ans=min(ans,curr[j+1]+1);
                    ans=min(ans,next[j]+1);
                    ans=min(ans,next[j+1]+1);
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        len1=word1.size();
        len2=word2.size();
        if(len1==0)
            return len2;
        if(len2==0)
            return len1;
        // vector<vector<int>> dp(len1,vector<int>(len2,-1));
        // return solve(word1,word2,0,0);
        // return solveMem(word1,word2,0,0,dp);
        // return solveTab(word1,word2);
        return solveOptimised(word1,word2);
    }
};