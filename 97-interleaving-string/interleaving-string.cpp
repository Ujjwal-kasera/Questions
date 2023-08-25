class Solution {
public:
    int len1,len2,len3;
    bool solveMem(string &s1,string &s2,string &s3,int idx1,int idx2,vector<vector<int>>&dp){
        if(idx1+idx2==len3)
            return 1;
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        bool ans=0;
        if(idx1<len1 && s1[idx1]==s3[idx1+idx2]){
            ans|= solveMem(s1,s2,s3,idx1+1,idx2,dp);
        }
        if(idx2<len2 && s2[idx2]==s3[idx1+idx2]){
            ans|= solveMem(s1,s2,s3,idx1,idx2+1,dp);
        }
        return dp[idx1][idx2]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        len1=s1.size();
        len2=s2.size();
        len3=s3.size();
        if(len1+len2!=len3)
            return 0;
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,-1));
        return solveMem(s1,s2,s3,0,0,dp);
    }
};