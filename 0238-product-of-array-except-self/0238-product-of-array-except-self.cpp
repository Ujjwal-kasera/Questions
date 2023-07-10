class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int> vec(len,1);
        int pro1=1,pro2=1;
        for(int i=0;i<len;++i){
            vec[i]*=pro1;
            pro1*=nums[i];
            vec[len-i-1]*=pro2;
            pro2*=nums[len-i-1];
        }
        return vec;
    }
};