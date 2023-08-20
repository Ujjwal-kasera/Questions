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
    
    // Greedy Apporach
//     bool ban(string &senate,char ch,int idx){
//         bool loop=0;
//         idx%=senate.size();
//         while(true){
//             if(idx==0)
//                 loop=1;
//             if(senate[idx]==ch){
//                 senate.erase(senate.begin()+idx);
//                 break;
//             }
//             idx=(idx+1)%senate.size();
//         }
//         return loop;
//     }
// public:
//     string predictPartyVictory(string senate) {
//         int dCount=0;
//         int rCount=0;
//         for(auto s:senate){
//             if(s=='R')
//                 rCount++;
//             else
//                 dCount++;
//         }
//         int idx=0;
//         while(rCount>0 && dCount>0){
//             if(senate[idx]=='R'){
//                 --dCount;
//                 if(ban(senate,'D',idx+1))
//                     --idx;
//             }
//             else if(senate[idx]=='D'){
//                 --rCount;
//                 if(ban(senate,'R',idx+1))
//                     --idx;
//             }
//             idx=(idx+1)%senate.size();
//         }
//         return dCount>0?"Dire":"Radiant";
//     }
};