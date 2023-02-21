class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len=nums.size();
        int start=0,end=len-1;
        int mid,Size;
        while(start<=end){
            mid=start+(end-start)/2;
            Size=mid-start;
            if(Size&1){
                if(mid-1>=0 && nums[mid-1]==nums[mid])
                    start=mid+1;
                else 
                    end=mid-1;
            }
            else{
                if(mid-1>=0 && nums[mid-1]==nums[mid])
                    end=mid;
                else if(mid+1<len && nums[mid+1]==nums[mid])
                    start=mid;
                else
                    break;
            }
        }
        return nums[mid];
    }
};