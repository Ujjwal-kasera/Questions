class Solution {
public:
    string reorganizeString(string s) {
        int len=s.size();
        vector<int> freq(26,0);
        for(int i=0;i<len;++i){
            freq[s[i]-'a']++;
        }
        auto maxiIdx=max_element(freq.begin(),freq.end())-freq.begin();
        int maxi=freq[maxiIdx];
        if(maxi>(len+1)>>1)
            return "";
        int idx=0;
        string res=s;
        while(freq[maxiIdx]>0){
            res[idx]='a'+maxiIdx;
            idx+=2;
            freq[maxiIdx]--;
        }
        for(int i=0;i<26;++i){
            while(freq[i]>0){
                if(idx>=len)
                    idx=1;
                res[idx]='a'+i;
                idx+=2;
                freq[i]--;
            }
        }
        return res;
    }
};