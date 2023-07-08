#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int len=weights.size();
        int tmp;
        vector<int> vec(len-1);
        for(int i=0;i<len-1;i++){
            vec[i]=weights[i]+weights[i+1];
        }
        sort(vec.begin(),vec.end());
        ll ans=0;
        for(int i=0;i<k-1;i++){
            ans+=vec[len-i-2]-vec[i];
        }
        return ans;
    }
};