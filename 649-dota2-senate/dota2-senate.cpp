class Solution {
    bool ban(string &senate,char ch,int idx){
        bool loop=0;
        idx%=senate.size();
        while(true){
            if(idx==0)
                loop=1;
            if(senate[idx]==ch){
                senate.erase(senate.begin()+idx);
                break;
            }
            idx=(idx+1)%senate.size();
        }
        return loop;
    }
public:
    string predictPartyVictory(string senate) {
        int dCount=0;
        int rCount=0;
        for(auto s:senate){
            if(s=='R')
                rCount++;
            else
                dCount++;
        }
        int idx=0;
        while(rCount>0 && dCount>0){
            if(senate[idx]=='R'){
                --dCount;
                if(ban(senate,'D',idx+1))
                    --idx;
            }
            else if(senate[idx]=='D'){
                --rCount;
                if(ban(senate,'R',idx+1))
                    --idx;
            }
            idx=(idx+1)%senate.size();
        }
        return dCount>0?"Dire":"Radiant";
    }
};