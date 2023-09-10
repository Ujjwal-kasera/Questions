/* Logic is that assume we have to calculate for 3 and we know for 2->6
For 2,we have 2P&2D option and placement Px/Dx,Px/Dx,Px/Dx,Px/Dx
For 3, we have 2P&2D+P&D ie same as for 2 but one more P&D pair
Possible position of placment for 3 will be 
_,Px/Dx,_,Px/Dx,_,Px/Dx,_,Px/Dx,_ in blank we can place P&D
Case 1. P_,Px/Dx,_,Px/Dx,_,Px/Dx,_,Px/Dx,_ we have 5 ways to place D
Case 1. P_,Px/Dx,_,Px/Dx,_,Px/Dx,_,Px/Dx,_ we have 5 ways to place D
Case 1. P_,Px/Dx,_,Px/Dx,_,Px/Dx,_,Px/Dx,_ we have 5 ways to place D
Case 1. P_,Px/Dx,_,Px/Dx,_,Px/Dx,_,Px/Dx,_ we have 5 ways to place D
Case 1. P_,Px/Dx,_,Px/Dx,_,Px/Dx,_,Px/Dx,_ we have 5 ways to place D
*/
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