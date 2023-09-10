#define MOD 1000000007
class Solution {
public:
    int countOrders(int n) {
        long long ans=1;
        int num,sum;
        for(int i=2;i<=n;++i){
            num=2*i-1;
            sum=num*(num+1)/2;
            ans*=sum;
            ans%=MOD;
        }
        return ans;
    }
};