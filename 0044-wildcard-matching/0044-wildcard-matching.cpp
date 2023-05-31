class Solution {
public:
    bool solve(string &s, string &p,int i,int j,vector<vector<int>> &dp){
        if(i<0 && j<0)
            return true;
        if(i>=0 && j<0)
            return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*')
                    return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool ans=false;
        if(p[j]=='?' || s[i]==p[j])
            ans=solve(s,p,i-1,j-1,dp);
        else if(p[j]=='*'){
            ans|=solve(s,p,i-1,j,dp);
            ans|=solve(s,p,i,j-1,dp);
        }
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return solve(s,p,s.size()-1,p.size()-1,dp);
    }
};