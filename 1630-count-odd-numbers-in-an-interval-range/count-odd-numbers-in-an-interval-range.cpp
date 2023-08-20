class Solution {
public:
    int countOdds(int low, int high) {
        int diff=high-low;
        int ans=diff>>1;
        if(low&1 || high&1){
            ++ans;
        }
        return ans;
    }
};