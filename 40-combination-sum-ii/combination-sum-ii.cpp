class Solution {
public:
    int len;
    vector<vector<int>> res;
    void solve(vector<int>&candidates,int target,vector<int>& ans,int index){
        if(target==0){
            res.push_back(ans);
            return;
        }
        if(index==len)
            return;
        for(int i=index;i<len;i++){
            if(i>index && candidates[i]==candidates[i-1])
                continue;
            if(target-candidates[i]<0)
                break;
            ans.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        len=candidates.size();
        vector<int> ans;
        solve(candidates,target,ans,0);
        return res;
    }
};