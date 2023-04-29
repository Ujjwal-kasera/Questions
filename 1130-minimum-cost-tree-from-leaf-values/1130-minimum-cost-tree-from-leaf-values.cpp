class Solution {
public:
    map<pair<int,int>,int> mp;
    /*
        Recursion
    int solveRec(vector<int>& arr,int left,int right){
        if(left>=right)
            return 0;
        int ans=INT_MAX;
        for(int i=left;i<right;i++){
            ans=min(ans,(mp[{left,i}]*mp[{i+1,right}]+solve(arr,left,i)+solve(arr,i+1,right)));
        }
        return ans;
    }
    */
    /*
        Memoziation
    int solveMem(vector<int>& arr,int left,int right,vector<vector<int>>&dp){
        if(left>=right)
            return 0;
        if(dp[left][right]!=-1)
            return dp[left][right];
        int ans=INT_MAX;
        for(int i=left;i<right;i++){
            ans=min(ans,(mp[{left,i}]*mp[{i+1,right}]+solveMem(arr,left,i,dp)+solveMem(arr,i+1,right,dp)));
        }
        return dp[left][right]=ans;
    }
    */
    
    /* Tabulation */
    int solveTab(vector<int>&arr){
        int len=arr.size();
        for(int i=0;i<len;i++){
            mp[{i,i}]=arr[i];
            for(int j=i+1;j<len;j++){
                mp[{i,j}]=max(arr[j],mp[{i,j-1}]);
            }
        }
        vector<vector<int>>dp(len,vector<int>(len,0));
        for(int left=len-1;left>=0;left--){
            for(int right=left;right<len;right++){
                if(left==right)
                    continue;
                else{
                    int ans=INT_MAX;
                    for(int i=left;i<right;i++){
                        ans=min(ans,(mp[{left,i}]*mp[{i+1,right}]+dp[left][i]+dp[i+1][right]));
                    }
                    dp[left][right]=ans;
                }
            }
        }
        return dp[0][len-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        /* For Recursion & Memoziation 
        int len=arr.size();
        for(int i=0;i<len;i++){
            mp[{i,i}]=arr[i];
            for(int j=i+1;j<len;j++){
                mp[{i,j}]=max(arr[j],mp[{i,j-1}]);
            }
        }
        return solveRec(arr,0,len-1);
        vector<vector<int>>dp(len,vector<int>(len,-1));
        return solveMem(arr,0,len-1,dp);
        */
        return solveTab(arr);
    }
};