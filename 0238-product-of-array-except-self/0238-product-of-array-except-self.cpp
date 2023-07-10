class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int> vec(len,1);
        int pro=1;
        for(int i=0;i<len;++i){
            vec[i]*=pro;
            pro*=nums[i];
        }
        pro=1;
        for(int i=len-1;i>=0;--i){
            vec[i]*=pro;
            pro*=nums[i];
        }
        return vec;
    }
};