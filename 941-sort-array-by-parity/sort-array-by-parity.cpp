class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int len=nums.size();
        int start=0,end=len-1;
        while(start<end){
            if(nums[end] & 1)
                end--;
            else if(!(nums[start] & 1))
                start++;
            else 
                swap(nums[start],nums[end]);
        }
        return nums;
    }
};