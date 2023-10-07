class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sptr=0,tptr=0;
        int slen=s.size();
        int tlen=t.size();
        while(true){
            if(tptr>=tlen && sptr>=slen)
                return true;
            if(tptr>=tlen)
                break;
            
            if(s[sptr]==t[tptr]){
                tptr++;
                sptr++;
            }
            else
                tptr++;
        }
        return false;
    }
};