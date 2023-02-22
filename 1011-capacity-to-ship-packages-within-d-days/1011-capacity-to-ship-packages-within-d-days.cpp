class Solution {
public:
    bool isPossible(vector<int> weights, int days, int mid, int len){
        int daysCount=1;
        int capacity=0;
        for(int i=0;i<len;i++){
            if(capacity+weights[i]<=mid)
                capacity+=weights[i];
            else{
                
                daysCount++;
                if(daysCount>days || weights[i]>mid)
                    return false;
                capacity=weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mini=1;
        int maxi;
        int len=weights.size();
        for(int i=0;i<len;i++)
            maxi+=weights[i];
        int ans=0;
        int mid=0;
        while(mini<=maxi){
            mid=mini+(maxi-mini)/2;
            if(isPossible(weights,days,mid,len)){
                ans=mid;
                maxi=mid-1;
            }
            else
                mini=mid+1;
        }
        return ans;
    }
};