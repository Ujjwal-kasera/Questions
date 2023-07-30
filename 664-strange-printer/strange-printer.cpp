class Solution {
public:
    // Memoziation
    // int solveMem(string &s,int left,int right,vector<vector<int>>&dp){
    //     if(left==right)
    //         return 1;
    //     if(dp[left][right]!=-1)
    //         return dp[left][right];
    //     int ans=INT_MAX,tmp;
    //     for(int k=left;k<right;k++){
    //         tmp=solveMem(s,left,k,dp)+solveMem(s,k+1,right,dp);
    //         ans=min(ans,tmp);
    //     }
    //     if(s[left]==s[right])
    //             ans--;
    //     dp[left][right]=ans;
    //     return ans;
    // } 
    
    // Tabulation
    int solveTab(string &s){
        int len=s.size();
        vector<vector<int>> dp(len+1,vector<int>(len+1,0));
        int ans,tmp,right;
        for(int left=len-1;left>=0;left--){
            dp[left][left]=1;
            for(int right=left+1;right<len;right++){
                ans=INT_MAX;
                for(int k=left;k<right;k++){
                    tmp=dp[left][k]+dp[k+1][right];
                    ans=min(ans,tmp);
                }
                if(s[left]==s[right])
                    ans--;
                dp[left][right]=ans;
            }
        }
        return dp[0][len-1];
    }
    int strangePrinter(string s) {
        return solveTab(s);
        // int len=s.size();
        // vector<vector<int>> dp(len,vector<int>(len,-1));
        // return solveMem(s,0,len-1,dp);
    }
};