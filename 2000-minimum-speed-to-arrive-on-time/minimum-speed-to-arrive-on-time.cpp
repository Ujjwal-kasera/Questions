class Solution {
public:
    int len;
    double isValidSpeed(vector<int>&dist,int speed){
        double time=0.0;
        for(int i=0;i<len-1;i++){
            time+=ceil(dist[i]/(double)speed);
        }
        time+=dist[len-1]/(double)speed;
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        len=dist.size();

        // Phle soch rha tha min aur max possible speed nikal 
        // le phr uspe binary search lga ke ans calculate kre
        // pr ek case ke lie valid nhi a rha tha 
        // int dis=0;
        // for(auto d:dist)
        //     dis+=d;
        // int minS=floor(dis/hour);
        // int maxS=ceil((dis+len-1)/hour);

        int minS=1;
        int maxS=1e7;
        int mid;
        int ans=-1;
        double time;
        while(minS<=maxS){
            mid=minS+(maxS-minS)/2;
            time=isValidSpeed(dist,mid);
            if(time<=hour){
                ans=mid;
                maxS=mid-1;
            }
            else
                minS=mid+1;
        }
        return ans;
    }
};