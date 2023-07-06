class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len=nums.size();
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int left,right=-1;
        for(int i=0;i<len;++i){
            if(nums[i]!=temp[i]){
                left=i;
                break;
            }
        }
        for(int i=len-1;i>=0;--i){
            if(nums[i]!=temp[i]){
                right=i;
                break;
            }
        }
        return (right==-1)?0:(right-left+1);
    }
};