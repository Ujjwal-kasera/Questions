#define ll long long
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        ll sum=0;
        ll minB=1;
        for(auto b:batteries){
            // selecting minimum limit of battery
            minB=(b<minB)?b:minB;
            sum+=b;
        }
        // Defining the maximum limit of battery
        ll maxB=sum/n;
        ll mid,ans,extra;
        while(minB<=maxB){
            mid=minB+(maxB-minB)/2;
            extra=0;
            // if a battery < mid,use all of its power.
            // if a battery > mid,only use mid power from it.
            // calculating total power we have if we run mid min
            for(auto b:batteries)
                extra+=(b<=mid)?b:mid;
                
            // Checking if we can run all n computer to mid time
            // does we have that (n*mid) power 
            if(mid*n<=extra){
                ans=mid;
                minB=mid+1;
            }
            else{
                maxB=mid-1;
            }
        }
        return ans;
    }
};