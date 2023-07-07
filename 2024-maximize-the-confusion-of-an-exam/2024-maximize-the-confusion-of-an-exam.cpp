class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int len=answerKey.size();
        int tcount=0,fcount=0;
        int res=0,start=0,diff;
        for(int i=0;i<len;i++){
            answerKey[i]=='T'?tcount++:fcount++;
            diff=min(tcount,fcount);
            while(diff>k){
                answerKey[start++]=='T'?tcount--:fcount--;
                diff=min(tcount,fcount);
            }
            res=max(res,(tcount+fcount));
        }
        return res;
    }
};