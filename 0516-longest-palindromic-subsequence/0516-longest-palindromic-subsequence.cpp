class Solution {
public:
    // int len;
    // Recursion
    // int solveRec(string &s1, string &s2,int i,int j){
    //     if(i>=len || j>=len)
    //         return 0;
    //     int ans;
    //     if(s1[i]==s2[j])
    //         ans=1+solveRec(s1,s2,i+1,j+1);
    //     else
    //         ans=max(solveRec(s1,s2,i+1,j),solveRec(s1,s2,i,j+1));
    //     return ans;
    // }
    
    // Memoziation
    // int solveMem(string &s1, string &s2,int i,int j,vector<vector<int>>&dp){
    //     if(i>=len || j>=len)
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     if(s1[i]==s2[j])
    //         dp[i][j]=1+solveMem(s1,s2,i+1,j+1,dp);
    //     else
    //         dp[i][j]=max(solveMem(s1,s2,i+1,j,dp),solveMem(s1,s2,i,j+1,dp));
    //     return dp[i][j];
    // }
    
    // Tabulation
    int solveTab(string s1,string s2){
        int len=s1.size();
        vector<vector<int>> dp(len+1,vector<int>(len+1,0));
        for(int i=len-1;i>=0;i--){
            for(int j=len-1;j>=0;j--){
                if(s1[i]==s2[j])
                    dp[i][j]=1+dp[i+1][j+1];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
    
    // Space Optimisation
    // int solveOptimised(string text1,string text2){
    //     int len1=text1.size();
    //     int len2=text2.size();
    //     vector<int> curr(len2+1,0);
    //     vector<int> next(len2+1,0);
    //     for(int i=len1-1;i>=0;i--){
    //         for(int j=len2-1;j>=0;j--){
    //             if(text1[i]==text2[j])
    //                 curr[j]=1+next[j+1];
    //             else
    //                 curr[j]=max(next[j],curr[j+1]);
    //         }
    //         next=curr;
    //     }
    //     return curr[0];
    // }
    int longestPalindromeSubseq(string s) {
        // len=s.size();
        string str=s;
        reverse(s.begin(),s.end());
        // vector<vector<int>> dp(len,vector<int>(len,-1));
        // return solveRec(str,s,0,0);
        // return solveMem(str,s,0,0,dp);
        return solveTab(str,s);
        // return solveOptimised(text1,text2);
    }
};