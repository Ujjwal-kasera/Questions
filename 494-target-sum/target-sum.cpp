class Solution {
public:
    int len,count=0,total=0,tar;
    int solveRec(vector<int>&nums,int t,int index,vector<vector<int>> &dp){
        if(index>=len){
            if(t==tar)
                return 1;
            return 0;
        }
        if(dp[index][t+total]!=-1)
            return dp[index][t+total];
        int plus=solveRec(nums,t-nums[index],index+1,dp);
        int minus=solveRec(nums,t+nums[index],index+1,dp);
        return dp[index][t+total]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        len=nums.size();
        tar=target;
        for(auto ele:nums)
            total+=ele;
        vector<vector<int>> dp(len,vector<int>(2*total+1,-1));
        return solveRec(nums,0,0,dp);
    }
};