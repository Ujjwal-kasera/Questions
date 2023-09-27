class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string tmp="";
        int len=s.size();
        long long slen=0;
        for(int i=0;i<len;i++){
            if(s[i]>='a' && s[i]<='z')
                slen++;
            else
                slen*=(s[i]-'0');
        }
        for(int i=len-1;i>=0;i--){
            if(s[i]<='9' && s[i]>='0'){
                slen/=(s[i]-'0');
                k%=slen;
            }
            else{
                if(k==0 || slen==k)
                    return string("")+s[i];
                slen--;
            }
        }
        return "";
    }
};