class Solution {
public:
    string removeKdigits(string num, int k) {
        int len=num.size();
        string res;
        char ch;
        for(int i=0;i<len;i++){
            ch=num[i];
            while(k>0 && !res.empty() && res.back()>ch){
                res.pop_back();
                k--;
            }
            res+=ch;
            if(res.size() == 1 && ch == '0')
                res.pop_back();
        }
        while(k>0 && res.size()>0){
            res.pop_back();
            k--;
        }
        return res==""?"0":res;
    }
};