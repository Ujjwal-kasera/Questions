class Solution {
public:
    string removeStars(string s) {
        string res="";
        int len=s.size();
        for(int i=0;i<len;i++){
            if(s[i]=='*')
                res.pop_back();
            else
                res+=s[i];
        }
        return res;
    }
};