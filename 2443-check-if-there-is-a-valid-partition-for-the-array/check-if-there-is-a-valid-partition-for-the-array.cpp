class Solution {
public:
    int len;
    int solveMem(vector<int>&nums,int idx,vector<int>&dp){
        if(idx>=len)
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=0;
        int i=idx+1;
        // 2 Equal
        if(i<len && nums[idx]==nums[i]){
            ans|=solveMem(nums,++i,dp);
        }
        // 3 Equal
        i=idx+1;
        while(i<len && (i-idx)<=2 && nums[idx]==nums[i]){
            i++;
        }
        if(i==(idx+3)){
            ans|=solveMem(nums,i,dp);
        }
        // 3 Consective
        i=idx+1;
        while(i<len && (i-idx)<=2 && nums[i-1]+1==nums[i])
            i++;
        if(i==idx+3){
            ans|=solveMem(nums,i,dp);
        }
        return dp[idx]=ans;
    }
    bool validPartition(vector<int>& nums) {
        len=nums.size();
        vector<int> dp(len,-1);
        return solveMem(nums,0,dp);
    }
};