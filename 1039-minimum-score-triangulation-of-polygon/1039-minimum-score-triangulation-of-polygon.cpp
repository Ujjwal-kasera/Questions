class Solution {
public:
    /*
    // Recursion
    int solve(vector<int>& v,int i,int j){
        if(i+1==j){
            return 0;
        }
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k)+solve(v,k,j));
        }
        return ans;
    }
    */
    
    //Memoziation
    int solve(vector<int>&v,int i,int j,vector<vector<int>>&dp){
        if(i+1==j){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k,dp)+solve(v,k,j,dp));
        }
        
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int size=values.size();
        vector<vector<int>> dp(size,vector<int>(size,-1));
        return solve(values,0,size-1,dp);
    }
};