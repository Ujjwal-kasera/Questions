class Solution {
public:
    int partitionString(string s) {
        int count=0;
        string res="";
        int str_len=s.size();
        int i=0;
        while(i<str_len){
            if(res.find(s[i])>res.size()){
                res+=s[i];
                i++;
            }
            else{
                res="";
                count++;
            }
        }
        return ++count;
    }
};