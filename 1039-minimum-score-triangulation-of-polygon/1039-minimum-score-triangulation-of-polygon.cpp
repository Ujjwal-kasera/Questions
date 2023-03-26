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
    
    /*
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
    */
    
    // Tabulation
    int solve(vector<int>&v){
        int size=v.size();
        vector<vector<int>> dp(size,vector<int>(size,0));
        for(int i=size-1;i>=0;i--){
            for(int j=i+2;j<size;j++){
                int ans=INT_MAX;
                for(int k=i+1;k<j;k++){
                    ans=min(ans,v[i]*v[j]*v[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][size-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        return solve(values);
    }
};