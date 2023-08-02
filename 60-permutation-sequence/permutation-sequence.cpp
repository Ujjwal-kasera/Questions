class Solution {
public:
    int k;
    string ans;
    void solve(vector<bool> &visited,string s,int n,int count){
        if(count==0){
            k--;
            if(k==0)
                ans=s;
            return;
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                visited[i]=1;
                s+=(i+'0');
                solve(visited,s,n,count-1);
                s.pop_back();
                visited[i]=0;
            }
        }
    }
    string getPermutation(int n, int k) {
        this->k=k;
        vector<bool>visited(n+1,0);
        string s;
        solve(visited,s,n,n);
        return ans;
    }
};