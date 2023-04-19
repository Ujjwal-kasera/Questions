class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int len=nums.size();
        int prod=1;
        for(int i=0;i<len;i++){
            prod*=nums[i];
            maxi=max(maxi,prod);
            if(prod==0)
                prod=1;
        }
        prod=1;
        for(int i=len-1;i>=0;i--){
            prod*=nums[i];
            maxi=max(maxi,prod);
            if(prod==0)
                prod=1;
        }
        return maxi;
    }
};