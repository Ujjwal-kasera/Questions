class Solution {
public:
    string smallestSubsequence(string s) {
        string res="";
        int len=s.size();
        vector<int> lastIndex(26,0);
        vector<bool> visited(26,0);
        for(int i=0;i<len;i++){
            lastIndex[s[i]-'a']=i;
        }
        char ch;
        for(int i=0;i<len;i++){
            ch=s[i];
            if(visited[ch-'a'])
                continue;
            while(res.size()>0 && res.back()>ch && i<lastIndex[res.back()-'a']){
                visited[res.back()-'a']=0;
                res.pop_back();
            }
            visited[ch-'a']=1;
            res+=ch;
        }
        return res;
    }
};