class Solution {
public:
    int ans=INT_MIN,n;
    void solve(vector<vector<int>>&requests,int index,int count,vector<int> &freq){
        if(index==requests.size()){
            for(int i=0;i<n;i++){
                if(freq[i])
                    return;
            }
            ans=max(ans,count);
            return;
        }
        freq[requests[index][0]]--;
        freq[requests[index][1]]++;
        solve(requests,index+1,count+1,freq);
        freq[requests[index][0]]++;
        freq[requests[index][1]]--;
        solve(requests,index+1,count,freq);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        this->n=n;
        vector<int> freq(n,0);
        solve(requests,0,0,freq);
        return ans;
    }
};