class Solution {
public:
    int minDeletions(string s) {
        int len=s.size();
        vector<int> freq(26,0);
        for(int i=0;i<len;++i)
            ++freq[s[i]-'a'];
        int res=0;
        unordered_set<int>st;
        for(int i=0;i<26;++i){
            while(freq[i] && st.count(freq[i])>0){
                --freq[i];
                res++;
            }
            st.insert(freq[i]);
        }
        return res;
    }
};