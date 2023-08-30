class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0,k;
        for(int i=nums.size()-2;i>=0;--i){
            k=(nums[i]-1)/nums[i+1];
            ans+=k;
            nums[i]/=(k+1);
        }
        return ans;
    }
};