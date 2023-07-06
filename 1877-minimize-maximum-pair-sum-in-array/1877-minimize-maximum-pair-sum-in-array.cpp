class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0,maxi=0;
        int left=0,right=nums.size()-1;
        while(left<right){
            sum=nums[left++]+nums[right--];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};