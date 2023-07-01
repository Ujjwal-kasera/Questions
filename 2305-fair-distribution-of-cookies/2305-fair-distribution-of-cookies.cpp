class Solution {
public:
    void solve(vector<int>& cookies, int &k,vector<int> &distri,int &ans,int index){
        if(index==cookies.size()){
            ans=min(ans,*max_element(distri.begin(),distri.end()));
            return;
        }
        for(int i=0;i<k;i++){
            distri[i]+=cookies[index];
            solve(cookies,k,distri,ans,index+1);
            distri[i]-=cookies[index];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distri(k,0);
        int ans=INT_MAX;
        solve(cookies,k,distri,ans,0);
        return ans;
    }
};