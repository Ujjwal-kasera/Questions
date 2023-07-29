class Solution {
public:
    int n,k;
    vector<int> vec;
    vector<vector<int>> ans;
    void solve(int index){
        if(!k){
            ans.push_back(vec);
            return;
        }
        for(int i=index;i<=n;i++){
            vec.push_back(i);
            k--;
            solve(i+1);
            k++;
            vec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        this->n=n;
        this->k=k;
        solve(1);
        return ans;
    }
};