class Solution {
public:
    int countbit(uint32_t n) {
        int count=0;
        for(int i=0;i<32;i++){
            if(n&1)
                count++;
            n=n>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i=1;i<=n;i++)
                res[i]=countbit(i);
        return res;
    }
};