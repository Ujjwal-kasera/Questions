// Approach here is to ban the closest opponent senator
// It will not only decrease its count but also preserve 
// our own senator from getting ban.
class Solution {
public:
    // Using two Queues
    string predictPartyVictory(string senate) {
        queue<int> R;
        queue<int> D;
        for(int i=0;i<senate.size();++i){
            if(senate[i]=='R')
                R.push(i);
            else
                D.push(i);
        }
        int rIdx,dIdx,len=senate.size();
        while(!R.empty() && !D.empty()){
            rIdx=R.front();
            dIdx=D.front();
            R.pop();
            D.pop();
            if(rIdx<dIdx)
                R.push(rIdx+len);
            else
                D.push(dIdx+len);
        }
        return D.empty()?"Radiant":"Dire";
    }
};