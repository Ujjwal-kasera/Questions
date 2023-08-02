class Solution {
public:
    int len;
    // Memoziation Space TC=O(N2) SC=O(N)
    // int solveMemSpace(vector<int> &nums,int index,int prev,vector<int>&dp){
    //     if(index>=len)
    //         return 0;
    //     if(dp[prev+1]!=-1)
    //         return dp[prev+1];
    //     int incl=0;
    //     if(prev==-1 || nums[index]>nums[prev])
    //         incl=solveMemSpace(nums,index+1,index,dp)+1;
    //     int excl=solveMemSpace(nums,index+1,prev,dp);
    //     return dp[prev+1]=max(incl,excl);
    // }

    // Memoziation TC=O(N2) SC=O(N2)
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

    // Binary Search TC=O(NlogN) SC=O(1)
    int SolveBinary(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<len;i++){
            if(nums[i]>ans.back())
                ans.push_back(nums[i]);
            else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        len=nums.size();
        return SolveBinary(nums);
        // vector<int> dp(len,-1);
        // return solveMemSpace(nums,0,-1,dp);
        // vector<vector<int>> dp(len,vector<int>(len,-1));
        // return solve(nums,0,-1,dp);
    }
};