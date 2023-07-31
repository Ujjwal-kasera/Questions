class Solution {
public:
    int len1,len2;
    int solveRec(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
        int ans=0;
        if(i==len1){
            while(j<len2)
                ans+=s2[j++];
            return ans;
        }
        if(j==len2){
            while(i<len1)
                ans+=s1[i++];
            return ans;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            ans=solveRec(s1,s2,i+1,j+1,dp);
        else{
            int del_s1=s1[i]+solveRec(s1,s2,i+1,j,dp);
            int del_s2=s2[j]+solveRec(s1,s2,i,j+1,dp);
            int del_both=s1[i]+s2[j]+solveRec(s1,s2,i+1,j+1,dp);
            ans=min({del_s1,del_s2,del_both});
        }
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        len1=s1.size();
        len2=s2.size();
        vector<vector<int>> dp(len1,vector<int>(len2,-1));
        return solveRec(s1,s2,0,0,dp);
    }
};