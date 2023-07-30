class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string ans=countAndSay(n-1);
        int len=ans.size();
        int count=1;
        string res="";
        for(int i=1;i<len;i++){
            if(ans[i]==ans[i-1])
                count++;
            else{
                res+=(to_string(count))+ans[i-1];
                count=1;
            }
        }
        res+=(to_string(count))+ans[len-1];
        return res;
    }
};