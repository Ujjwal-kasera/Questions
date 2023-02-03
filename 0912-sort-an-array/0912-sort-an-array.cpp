class Solution {
    // void merge(vector<int> &nums,int beg,int mid,int end){
    //     int len1=mid-beg+1;
    //     int len2=end-mid;
    //     vector<int> nums1(len1);
    //     vector<int> nums2(len2);
    //     for(int i=0;i<len1;i++)
    //         nums1[i]=nums[beg+i];
    //     for(int i=0;i<len2;i++)
    //         nums2[i]=nums[mid+i+1];
    //     int i=0,j=0,k=beg;
    //     while(i<len1 && j<len2){
    //         if(nums1[i]<nums[j])
    //             nums[k++]=nums1[i++];
    //         else
    //             nums[k++]=nums2[j++];
    //     }
    //     while(i<len1)
    //         nums[k++]=nums1[i++];
    //     while(j<len2)
    //         nums[k++]=nums2[j++];
    //     return ;
    // }
    // void mergeSort(vector<int> &nums,int beg,int end){
    //     while(beg<end){
    //         int mid=beg+(end-beg)/2;
    //         mergeSort(nums,beg,mid);
    //         mergeSort(nums,mid+1,end);
    //         merge(nums,beg,mid,end);
    //     }
    //     return;
    // }
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }
};