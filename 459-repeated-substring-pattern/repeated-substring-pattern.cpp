class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len=s.size();
        for(int i=1;i<=len>>1;++i){
            if(len%i==0){
                if(s.substr(0,len-i)==s.substr(i)){
                    return true;
                }
            }
        }
        return false;        
    }
    // bool repeatedSubstringPattern(string s) {
    //     int len=s.size();
    //     if(len==1)
    //         return 0;
    //     string temp=s;
    //     len>>=1;
    //     for(int i=0;i<len;i++){
    //         temp.push_back(temp[0]);
    //         temp=temp.substr(1);
    //         if(s==temp)
    //             return 1;
    //     }
    //     return 0;
    // }
};