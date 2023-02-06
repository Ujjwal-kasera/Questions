class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len=gas.size();
        int fuel_rem=0;
        int total_fuel=0;
        int ans=0;
        for(int i=0;i<len;i++){
            total_fuel+=gas[i]-cost[i];
            fuel_rem+=gas[i]-cost[i];
            if(fuel_rem<0){
                fuel_rem=0;
                ans=i+1;
            }
        }
        return (total_fuel<0)?-1:ans;
    }
};