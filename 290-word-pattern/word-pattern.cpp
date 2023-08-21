class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> p2s;
        unordered_map<string,char> s2p;
        int pat_len=pattern.size();
        int str_len=s.size();
        int idx=0;
        string tmp="";
        for(int i=0;i<pat_len;++i){
            if(idx<str_len){
                while(idx<str_len && s[idx]!=' '){
                    tmp+=s[idx];
                    idx++;
                }
            }
            else 
                return false;
            idx++;
            if(p2s.count(pattern[i]) && p2s[pattern[i]]!=tmp)
                return false;
            if(s2p.count(tmp) && s2p[tmp]!=pattern[i])
                return false;
            p2s[pattern[i]]=tmp;
            s2p[tmp]=pattern[i];
            tmp="";
        }
        if(idx>=str_len)
            return true;
        return false;
    }
};