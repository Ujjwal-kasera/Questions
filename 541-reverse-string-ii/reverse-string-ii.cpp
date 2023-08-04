class Solution {
public:
    string reverseStr(string s, int k) {
        int len=s.size();
        string str="",res="";
        int cnt;
        int i=0;
        while(i<len){
            str="",cnt=0;
            while(i<len && cnt<k){
                str+=s[i++];
                cnt++;
            }
            reverse(str.begin(),str.end());
            res+=str;
            cnt=0;
            while(i<len && cnt<k){
                res+=s[i++];
                cnt++;
            }
        }
        return res;
    }
};