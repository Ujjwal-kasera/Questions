class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        int len1=word1.size(),len2=word2.size();
        string res="";
        while(i<len1 || j<len2){
            if(i<len1)
                res.push_back(word1[i++]);
            if(j<len2)
                res.push_back(word2[j++]);
        }
        return res;
    }
};