class Solution {
public:
    int largestVariance(string s) {
        int len=s.size();
        vector<int> freq(26,0);
        for(int i=0;i<len;i++){
            freq[s[i]-'a']++;
        }
        int res=0,diff=0;
        int maxi=0,mini=0;
        int left=0;
        char ch1,ch2;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j || !freq[i] || !freq[j])
                    continue;
                ch1='a'+i;
                ch2='a'+j;
                mini=0,maxi=0;
                left=freq[j];
                for(int k=0;k<len;k++){
                    if(s[k]==ch1)
                        maxi++;
                    if(s[k]==ch2){
                        mini++;
                        left--;
                    }
                    if(maxi<mini && left>0){
                        maxi=0;
                        mini=0;
                    }
                    if(mini>0){
                        res=max(res,maxi-mini);
                    }
                }
            }
        }
        return res;
    }
};