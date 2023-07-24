class Solution {
public:
    double myPow(double x, int n) {
        int pow=n;
        n=abs(n);
        double res=1;
        while(n>0){
            if(n&1)
                res*=x;
            x*=x;
            n=n>>1;
        }
        if(pow<0)
            res=1/res;
        return res;
    }
};