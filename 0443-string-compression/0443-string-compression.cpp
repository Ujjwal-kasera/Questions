class Solution {
public:
    int compress(vector<char>& chars) {
        char prev=chars[0],curr;
        int count=1,res=0;
        int len=chars.size();
        string str;
        for(int i=1;i<len;i++){
            curr=chars[i];
            if(curr==prev){
                count++;
                continue;
            }
            else{
                chars[res++]=prev;
                if(count>1){
                    str=to_string(count);
                    for(auto s:str)
                        chars[res++]=s;
                }
                count=1;
                prev=curr;
            }
        }
        chars[res++]=prev;
        if(count>1){
            str=to_string(count);
            for(auto s:str)
                chars[res++]=s;
        }
        return res;
    }
};