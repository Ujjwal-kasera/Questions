class Solution {
    // int solveRec(vector<int> &nums,int len){
    //     if(len<0)
    //         return 0;
    //     if(len==0)
    //         return nums[0];
    //     return max(solveRec(nums,len-2)+nums[len],solveRec(nums,len-1));
    // }
    // int solveMem(vector<int> &nums,vector<int> &dp,int len){
    //     if(len<0)
    //         return 0;
    //     else if(len==0)
    //         return nums[0];
    //     else if(dp[len]!=-1)
    //         return dp[len];
    //     return max(solveRec(nums,dp,len-2)+nums[len],solveRec(nums,dp,len-1));
    // }
    // int solveTab(vector<int> &nums){
    //     int len=nums.size();
    //     vector<int>dp(len+1,0);
    //     dp[0]=0;
    //     dp[1]=nums[0];
    //     for(int i=1;i<len;i++)
    //         dp[i+1]=max(dp[i-1]+nums[i],dp[i]);
    //     return dp[len];
    // }
    int solveOptimise(vector<int>nums){
        int len=nums.size();
        int prev2=0;
        int prev1=nums[0];
        int tmp;
        for(int i=1;i<len;i++){
            tmp=prev1;
            prev1=max(prev2+nums[i],prev1);
            prev2=tmp;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        return solveOptimise(nums);
    }
};