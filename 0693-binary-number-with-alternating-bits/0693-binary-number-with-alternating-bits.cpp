class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp;
        while(n){
            int temp=n;
            n>>=1;
            if(!(temp%2 ^ n%2))
                return false;
        }
        return true;
    }
};