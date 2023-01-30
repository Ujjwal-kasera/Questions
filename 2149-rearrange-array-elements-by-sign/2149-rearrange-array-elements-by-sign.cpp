class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]>0)
                positive.push_back(nums[i]);
            else 
                negative.push_back(nums[i]);
        }
        int p=0,n=0;
        for(int i=0;i<len;i++){
            nums[i++]=positive[p++];
            nums[i]=negative[n++];
        }
        return nums;
    }
};