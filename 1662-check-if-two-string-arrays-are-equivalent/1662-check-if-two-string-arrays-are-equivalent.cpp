class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int index1=0,index2=0;
        int char1=0,char2=0;
        int len1=word1.size();
        int len2=word2.size();
        while(index1<len1 && index2<len2){
            if(word1[index1][char1++]!=word2[index2][char2++])
                return false;
            if(char1==word1[index1].size()){
                index1++;
                char1=0;
            }
            if(char2==word2[index2].size()){
                index2++;
                char2=0;
            }
        }
        return index1==len1 && index2==len2;
    }
};