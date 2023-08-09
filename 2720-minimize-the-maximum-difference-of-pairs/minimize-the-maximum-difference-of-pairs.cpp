class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        int start=0,end=nums[len-1]-nums[0];
        int diff,count,ans=0;
        while(start<end){
            diff=start+(end-start)/2;
            count=0;
            for(int i=0;i<len-1;i++){
                if((nums[i+1]-nums[i])<=diff){
                    count++;
                    i++;
                }
            }
            if(count<p){
                start=diff+1;
            }
            else{
                end=diff;
            }
        }
        return start;
    }
};