class Solution {
public:
    // Isme Robber ke pas do option hoge 
    // Case 1: ya to robber 1 aur n-1 house rob krega
    // Case 2: ya to robber 2 aur n house rob krega
    // Same logic rhega jo house robber me use kiye the bs ek difference hoga
    // ki hm do variable use krege phla to case 1 ke result ko denote krega aur
    // dusra case 2 ko indicate krega
    // aur last me hm dono ka max return krege
    int rob(vector<int>& nums) {
        int len=nums.size();
        
        // Case 1
        int prev11=nums[0];
        int prev12=0;
        // Case 2
        int prev21=0;
        int prev22=0;
        int tmp;
        for(int i=1;i<len;i++){
            // Case 1
            if(i!=len-1){
                tmp=prev11;
                prev11=max(prev12+nums[i],prev11);
                prev12=tmp;
            }
            // Case 2
            tmp=prev21;
            prev21=max(prev22+nums[i],prev21);
            prev22=tmp;
        }
        return max(prev11,prev21);
    }
};