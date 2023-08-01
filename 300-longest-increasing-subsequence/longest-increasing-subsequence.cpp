class Solution {
public:
    int len;
    int solveMemSpace(vector<int> &nums,int index,int prev,vector<int>&dp){
        if(index>=len)
            return 0;
        if(dp[prev+1]!=-1)
            return dp[prev+1];
        int incl=0;
        if(prev==-1 || nums[index]>nums[prev])
            incl=solveMemSpace(nums,index+1,index,dp)+1;
        int excl=solveMemSpace(nums,index+1,prev,dp);
        return dp[prev+1]=max(incl,excl);
    }
    // int solveMem(vector<int> &nums,int index,int prev,vector<vector<int>>&dp){
    //     if(index>=len)
    //         return 0;
    //     if(dp[index][prev+1]!=-1)
    //         return dp[index][prev+1];
    //     int incl=0;
    //     if(prev==-1 || nums[index]>nums[prev])
    //         incl=solve(nums,index+1,index,dp)+1;
    //     int excl=solve(nums,index+1,prev,dp);
    //     return dp[index][prev+1]=max(incl,excl);
    // }
    int lengthOfLIS(vector<int>& nums) {
        len=nums.size();
        vector<int> dp(len,-1);
        return solveMemSpace(nums,0,-1,dp);
        // vector<vector<int>> dp(len,vector<int>(len,-1));
        // return solve(nums,0,-1,dp);
    }
};