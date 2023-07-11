class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        if(len1!=len2)
            return false;
        multiset<int> st1,st2;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<len1;i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq1[i]==0 && freq2[i]==0)
                continue;
            if(freq1[i]==0 || freq2[i]==0)
                return 0;
            st1.insert(freq1[i]);
            st2.insert(freq2[i]);
        }
        return st1==st2;
    }
};