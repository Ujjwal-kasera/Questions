class Solution {
public:
    bool solve(vector<int>& nums,int index,int target,vector<vector<int>> &dp){
        if(target==0)
            return 1;
        if(index>=nums.size() || target<0)
            return 0;
        if(dp[index][target]!=-1)
            return dp[index][target];
        bool incl=solve(nums,index+1,target-nums[index],dp);
        bool excl=solve(nums,index+1,target,dp);
        dp[index][target]=incl|excl;
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int len=nums.size();
        int total=0;
        for(auto i:nums)
            total+=i;
        if(total&1)
            return 0;
        vector<vector<int>>dp(len,vector<int>(total/2+1,-1));
        return solve(nums,0,total/2,dp);
        
    }
};