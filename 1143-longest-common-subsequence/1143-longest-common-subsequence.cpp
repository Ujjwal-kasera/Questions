class Solution {
public:
    // int len1,len2;
    // Recursion
    // int solveRec(string &text1, string &text2,int i,int j){
    //     if(i>=len1 || j>=len2)
    //         return 0;
    //     int ans;
    //     if(text1[i]==text2[j])
    //         ans=1+solveRec(text1,text2,i+1,j+1);
    //     else
    //         ans=max(solveRec(text1,text2,i+1,j),solveRec(text1,text2,i,j+1));
    //     return ans;
    // }
    
    // Memoziation
    // int solveMem(string &text1, string &text2,int i,int j,vector<vector<int>>&dp){
    //     if(i>=len1 || j>=len2)
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     if(text1[i]==text2[j])
    //         dp[i][j]=1+solveMem(text1,text2,i+1,j+1,dp);
    //     else
    //         dp[i][j]=max(solveMem(text1,text2,i+1,j,dp),solveMem(text1,text2,i,j+1,dp));
    //     return dp[i][j];
    // }
    
    // Tabulation
    // int solveTab(string text1,string text2){
    //     int len1=text1.size();
    //     int len2=text2.size();
    //     vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
    //     for(int i=len1-1;i>=0;i--){
    //         for(int j=len2-1;j>=0;j--){
    //             if(text1[i]==text2[j])
    //                 dp[i][j]=1+dp[i+1][j+1];
    //             else
    //                 dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
    //         }
    //     }
    //     return dp[0][0];
    // }
    
    // Space Optimisation
    int solveOptimised(string text1,string text2){
        int len1=text1.size();
        int len2=text2.size();
        vector<int> curr(len2+1,0);
        vector<int> next(len2+1,0);
        for(int i=len1-1;i>=0;i--){
            for(int j=len2-1;j>=0;j--){
                if(text1[i]==text2[j])
                    curr[j]=1+next[j+1];
                else
                    curr[j]=max(next[j],curr[j+1]);
            }
            next=curr;
        }
        return curr[0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        // len1=text1.size();
        // len2=text2.size();
        // vector<vector<int>> dp(len1,vector<int>(len2,-1));
        // return solveRec(text1,text2,0,0);
        // return solveMem(text1,text2,0,0,dp);
        // return solveTab(text1,text2);
        return solveOptimised(text1,text2);
    }
};