class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int len=s.size();
        unordered_map<char,char> sMp,tMp;
        for(int i=0;i<len;++i){
            if(sMp[s[i]] && sMp[s[i]]!=t[i])
                return false;
            if(tMp[t[i]] && tMp[t[i]]!=s[i])
                return false;
            sMp[s[i]]=t[i];
            tMp[t[i]]=s[i];
        }
        return true;
    }
};