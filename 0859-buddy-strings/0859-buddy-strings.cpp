class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int diff=0;
        int slen=s.size();
        int glen=goal.size();
        if(slen!=glen)
            return 0;
        vector<int>sArr(26,0);
        vector<int>goalArr(26,0);
        for(int i=0;i<slen;i++){
            sArr[s[i]-'a']++;
            goalArr[goal[i]-'a']++;
            if(s[i]!=goal[i])
                diff++;
        }
        int maxFreq=0;
        for(auto count:sArr)
            maxFreq=max(maxFreq,count);
        
        if((diff==2 && sArr==goalArr) || (diff==0 && maxFreq>1))
            return 1;
        return 0;
    }
};