class Solution {
public:
    string removeStars(string s) {
        string res="";
        int len=s.size();
        for(auto ch:s){
            if(ch=='*')
                res.pop_back();
            else
                res+=ch;
        }
        return res;
    }
};