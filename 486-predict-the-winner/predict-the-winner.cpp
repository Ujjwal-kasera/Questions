class Solution {
public:
    // Logic ye h ki hme value to pucha nhi ki kitna score h hme to bs 
    // difference se mtlb h dono ke score ka..
    // Agr 1 person ka 100 ya 10 score h and 2 ka 10 to diff +ve hi aega 
    // aur 1 winner hoga or vice-versa..
    // Ek person ke lie jo gain hoga wo dusre ke lie negative gain hoga
    // Phle 1st person khel rha to islie hmsha uske lie hi ans aega ki 
    // uska kitna difference h 2nd se

    // Recursion
    // int solveRec(vector<int> &nums,int s,int e){
    //     if(s>e)
    //         return 0;
    //     if(s==e)
    //         nums[s];
    //     int start=nums[s]-solveRec(nums,s+1,e);
    //     int end=nums[e]-solveRec(nums,s,e-1);
    //     return max(start,end);
    // }
    
    // Memoziation
    int solveMem(vector<int> &nums,int s,int e,vector<vector<int>>&dp){
        if(s>e)
            return 0;
        if(s==e)
            nums[s];
        if(dp[s][e]!=-1)
            return dp[s][e];
        int start=nums[s]-solveMem(nums,s+1,e,dp);
        int end=nums[e]-solveMem(nums,s,e-1,dp);
        return dp[s][e]=max(start,end);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int len=nums.size();
        vector<vector<int>>dp(len,vector<int>(len,-1));
        return solveMem(nums,0,len-1,dp)>=0;
        // return solveRec(nums,0,len-1)>=0;
    }
};