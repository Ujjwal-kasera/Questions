class Solution {
public:
    int longestValidParentheses(string s) {
        // int len=s.size();
        // vector<int> dp(len,0);
        // int ans=0;
        // for(int i=1;i<len;i++){
        //     if(s[i]==')'){
        //         if(s[i-1]=='(')
        //             dp[i]=(i-2<0?0:dp[i-2])+2;
        //         else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='(')
        //             dp[i]=dp[i-1]+(i-dp[i-1]-2<0?0:dp[i-dp[i-1]-2])+2;
        //         ans=max(ans,dp[i]);
        //     }
        // }
        // return ans;
        
        int len=s.size();
        int lopen=0;
        int lclose=0;
        int ropen=0;
        int rclose=0;
        int ans=0;
        for(int i=0;i<len;i++){
            if(s[i]=='(')
                lopen++;
            else
                lclose++;
            
            if(s[len-i-1]=='(')
                ropen++;
            else
                rclose++;
            
            if(lopen==lclose)
                ans=max(ans,lopen+lclose);
            if(lclose>lopen)
                lopen=lclose=0;
            
            if(ropen==rclose)
                ans=max(ans,ropen+rclose);
            if(ropen>rclose)
                ropen=rclose=0;
        }
        return ans;
    }
};