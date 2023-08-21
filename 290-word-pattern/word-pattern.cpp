class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> c2s;
        unordered_map<string,char> s2c;
        int len=pattern.size();
        int n=s.size();
        int index=0;
        string tmp="";
        for(int i=0;i<len;++i){
            if(index<n){
                while(index<n && s[index]!=' '){
                    tmp+=s[index];
                    index++;
                }
            }
            else 
                return false;
            index++;
            if(c2s.count(pattern[i]) && c2s[pattern[i]]!=tmp)
                return false;
            if(s2c.count(tmp) && s2c[tmp]!=pattern[i])
                return false;
            c2s[pattern[i]]=tmp;
            s2c[tmp]=pattern[i];
            tmp="";
        }
        if(index>=n)
            return true;
        return false;
    }
};