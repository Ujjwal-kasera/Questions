class Solution {
public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int len=gas.size();
//         int fuel_rem=0;
//         int total_fuel=0;
//         int ans=0;
//         for(int i=0;i<len;i++){
//             total_fuel+=gas[i]-cost[i];
//             fuel_rem+=gas[i]-cost[i];
//             if(fuel_rem<0){
//                 fuel_rem=0;
//                 ans=i+1;
//             }
//         }
//         return (total_fuel<0)?-1:ans;
//     }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len=gas.size();
        int start=0;
        int fuel_rem=0;
        int fuel_rec=0;
        for(int i=0;i<len;i++){
            fuel_rem+=gas[i]-cost[i];
            if(fuel_rem<0){
                fuel_rec+=fuel_rem;
                start=i+1;
                fuel_rem=0;
            }
        }
        return (fuel_rec+fuel_rem)>=0?start:-1;
    }
};