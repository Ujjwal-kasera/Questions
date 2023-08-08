class Solution {
public:
    bool winnerOfGame(string colors) {
        //initializing the counter variable
        int countA=0;
        int countB=0;
        for(int i=1;i<colors.size();i++){
            //matching condition for A and B
            if(colors[i-1] == colors[i] && colors[i+1] == colors[i]){
                if(colors[i] =='A'){
                    countA++;
                }
                //for B
                else{
                    countB++;
                }
            }
        }
        // will return true if (countA>countB) else false
        return countA>countB;
    }
};