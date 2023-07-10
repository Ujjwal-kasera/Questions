class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rlen=ransomNote.size();
        int mlen=magazine.size();
        vector<int> vec(26,0);
        for(int i=0;i<rlen;i++)
            vec[ransomNote[i]-'a']--;
        for(int i=0;i<mlen;i++)
            vec[magazine[i]-'a']++;
        for(int i=0;i<26;i++){
            if(vec[i]<0)
                return false;
        }
        return true;
    }
};