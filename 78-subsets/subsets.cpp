class Solution {
public:
    int len;
    vector<vector<int>> res;
    void backtrack(vector<int>&nums,vector<int>&temp,int idx){
            res.push_back(temp);
        for(int i=idx;i<len;i++){
            temp.push_back(nums[i]);
            backtrack(nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        len=nums.size();
        vector<int> temp;
        backtrack(nums,temp,0);
        return res;
    }
};