class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len=nums.size(),totalSum=0,sum=0,count=-1,tmp;
        for(int i=0;i<len;++i)
            totalSum+=nums[i];
        int s=0,e=0;
        while(e<len){
            sum+=nums[e];
            while(s<=e && sum>(totalSum-x)){
                sum-=nums[s];
                s++;
            }
            if(sum==(totalSum-x)){
                count=max(count,e-s+1);
            }
            e++;
        }
        return count==-1?-1:len-count;
    }
};