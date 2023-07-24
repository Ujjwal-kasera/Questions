class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        int index1=0,index2=0;
        string res="";
        while(true){
        if(index1<len1)
            res+=word1[index1++];
        if(index2<len2)
            res+=word2[index2++];
        if(index1==len1 && index2==len2)
            break;
        }
        return res;  
    }
};