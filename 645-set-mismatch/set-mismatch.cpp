class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup=-1,mis=-1;
        for(auto ele:nums){
            if(nums[abs(ele)-1]<0)
                dup=abs(ele);
            else{
                nums[abs(ele)-1]*=-1;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                mis=i+1;
                break;
            }
        }
        return {dup,mis};
    }
};