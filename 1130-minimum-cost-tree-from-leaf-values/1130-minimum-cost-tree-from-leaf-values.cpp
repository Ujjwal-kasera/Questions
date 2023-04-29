class Solution {
public:
    map<pair<int,int>,int> mp;
    /*
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
    int mctFromLeafValues(vector<int>& arr) {
        int len=arr.size();
        for(int i=0;i<len;i++){
            mp[{i,i}]=arr[i];
            for(int j=i+1;j<len;j++){
                mp[{i,j}]=max(arr[j],mp[{i,j-1}]);
            }
        }
        vector<vector<int>>dp(len,vector<int>(len,-1));
        return solveMem(arr,0,len-1,dp);
    }
};