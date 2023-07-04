class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int len=s.size();
        int max_count=0;
        vector<int> freq(26,0);
        for(int i=0;i<len;i++){
            max_count=max(max_count,++freq[s[i]-'a']);
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0 && freq[i]!=max_count)
                return 0;
        }
        return 1;
    }
};