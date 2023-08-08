class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> s1(26,0),s2(26,0);
        int len=word1.size();
        for(int i=0;i<len;i++){
            s1[word1[i]-'a']++;
            s2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(abs(s1[i] - s2[i]) > 3)
            return false;
        }
        return true;
        
    }
};