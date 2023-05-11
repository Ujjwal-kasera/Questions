class Solution {
public:
    int len1;
    int len2;
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j,vector<vector<int>> &dp){
        if(i>=len1 || j>=len2)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        vector<int>::iterator it;
        it=find(nums2.begin()+j+1,nums2.end(),nums1[i]);
        int incl=0,excl=0;
        int tmp=it-nums2.begin();
        if(tmp!=len2 && tmp>j)
            incl=max(incl,1+solve(nums1,nums2,i+1,tmp,dp));
        excl=max(excl,solve(nums1,nums2,i+1,j,dp));
        return dp[i][j]=max(incl,excl);
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),INT_MAX);
        nums2.insert(nums2.begin(),INT_MAX);
        len1=nums1.size();
        len2=nums2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,-1));
        return solve(nums1,nums2,0,0,dp);
    }
};