class Solution {
public:
    int bestClosingTime(string customers) {
        int yes=0;
        // int ans=0;
        // int penalty = yes;
        // int no=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y'){
                yes++;
            }
        }
        int ans=0; int penalty = yes;int no=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='N'){
                no++;
            }
            else{
                yes--;
            }
            int curr_penalty= yes + no;
            if(curr_penalty<penalty){
                ans=i+1;
                penalty = curr_penalty;
            }
        }
        return ans;
        
        
    }
};