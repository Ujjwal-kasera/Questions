class Solution {
public:
    int len;
    vector<vector<int>> res;
    void backTrack(vector<int>&nums,vector<int>&temp,int idx){
            res.push_back(temp);
        for(int i=idx;i<len;i++){
            temp.push_back(nums[i]);
            backTrack(nums,temp,i+1);
            temp.pop_back();
        }
    }
    void bitMunipulation(vector<int>&nums,vector<int>&temp){
        for(int i=0;i<(1<<len);i++){
            temp.clear();
            for(int j=0;j<len;j++)
                if(i&(1<<j))
                    temp.push_back(nums[j]);
            res.push_back(temp);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        len=nums.size();
        vector<int> temp;
        // backTrack(nums,temp,0);
        bitMunipulation(nums,temp);
        return res;
    }
};