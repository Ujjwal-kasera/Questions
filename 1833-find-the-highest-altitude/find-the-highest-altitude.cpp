class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int len=gain.size();
        int res=gain[0];
        for(int i=1;i<len;i++){
            gain[i]+=gain[i-1];
            res=max(res,gain[i]);
        }
        return max(res,0);
    }
};