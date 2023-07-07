class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start=0;
        int len=nums.size();
        if(len<=2)
            return len;
        for(int i=2;i<len;i++){
            if(nums[start]!=nums[i]){
                nums[start+2]=nums[i];
                start++;
            }
        }
        return start+2;
    }
};