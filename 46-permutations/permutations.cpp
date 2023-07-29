class Solution {
public:
    int len;
    vector<vector<int>> ans;
    void solve(vector<int>&nums,vector<bool> &visited,vector<int>&vec,int count){
        if(!count){
            ans.push_back(vec);
            return;
        }
        for(int i=0;i<len;i++){
            if(!visited[i]){
                visited[i]=1;
                vec.push_back(nums[i]);
                solve(nums,visited,vec,count-1);
                vec.pop_back();
                visited[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        len=nums.size();
        vector<bool>visited(len,0);
        vector<int> vec;
        solve(nums,visited,vec,len);
        return ans;
    }
};