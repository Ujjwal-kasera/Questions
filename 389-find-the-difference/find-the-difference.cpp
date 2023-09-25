class Solution {
public:
    char findTheDifference(string s, string t) {
        int len=t.size();
        char temp=t[len-1];
        for(int i=0;i<len-1;i++){
            temp^=s[i];
            temp^=t[i];
        }
        return temp;
    }
};