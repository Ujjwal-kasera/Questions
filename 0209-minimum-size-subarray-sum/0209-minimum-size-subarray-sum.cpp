class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=nums.size(),res=1e9+7;
        int sum=0,count=0,start=0;
        for(int i=0;i<len;i++){
            sum+=nums[i];
            count++;
            while(sum>=target){
                res=min(res,count);
                sum-=nums[start++];
                count--;
            }
        }
        return (res==1e9+7)?0:res;
    }
};