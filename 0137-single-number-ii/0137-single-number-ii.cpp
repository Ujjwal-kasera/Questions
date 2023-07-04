class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int count;
        int len=nums.size();
        for(int i=0;i<32;i++){
            count=0;
            for(int j=0;j<len;j++){
                count+=(nums[j]&1);
                nums[j]>>=1;
            }
            if(count%3!=0)
                ans+=count%3<<i;
        }
        return ans;
    }
};