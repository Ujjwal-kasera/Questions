class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long res=0,sum=0;
        int len=nums.size();
        for(int i=0;i<len;i++){
            sum+=nums[i];
            res=max(res,(sum+i)/(i+1));
        }
        return res;
    }
};