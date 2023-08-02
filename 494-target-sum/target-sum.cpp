class Solution {
public:
    int len,count=0,total=0,tar;

    // Memoziation
    // int solveMem(vector<int>&nums,int t,int index,vector<vector<int>> &dp){
    //     if(index>=len){
    //         if(t==tar)
    //             return 1;
    //         return 0;
    //     }
    //     if(dp[index][t+total]!=-1)
    //         return dp[index][t+total];
    //     int plus=solveMem(nums,t-nums[index],index+1,dp);
    //     int minus=solveMem(nums,t+nums[index],index+1,dp);
    //     return dp[index][t+total]=plus+minus;
    // }

    // Tabulation
    int solveTab(vector<int>&nums){
        vector<vector<int>> dp(len+1,vector<int>(2*total+1,0));
        dp[len][tar+total]=1;
        for(int index=len-1;index>=0;--index){
            for(int t=total;t>=-total;t--){
                if((t-nums[index]+total)>=0  && (t-nums[index]+total)<=2*total)
                    dp[index][t+total]+=dp[index+1][t-nums[index]+total];
                if((t+nums[index]+total)>=0  && (t+nums[index]+total)<=2*total)
                    dp[index][t+total]+=dp[index+1][t+nums[index]+total];
            }
        }
        return dp[0][0+total];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        len=nums.size();
        tar=target;
        for(auto ele:nums)
            total+=ele;
        if(abs(target)>total )
            return 0;
        return solveTab(nums);
        // vector<vector<int>> dp(len,vector<int>(2*total+1,-1));
        // return solveMem(nums,0,0,dp);
    }
};