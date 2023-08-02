class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=INT_MIN;
        int count=0;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]==1)
                count++;
            else{
                ans=max(ans,count);
                count=0;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};