class Solution {
public:
    int solveRec(vector<int> &nums,int s,int e){
        if(s>e)
            return 0;
        if(s==e)
            nums[s];
        int start=nums[s]-solveRec(nums,s+1,e);
        int end=nums[e]-solveRec(nums,s,e-1);
        return max(start,end);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int len=nums.size();
        return solveRec(nums,0,len-1)>=0;
    }
};