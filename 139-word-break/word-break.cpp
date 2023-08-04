class Solution {
public:
    int len;
    string s;
    set<string> st;
    bool solve(int index,vector<int>&dp){
        if(index==len)
            return true;
        if(dp[index]!=-1)
            return dp[index];
        for(int i=index;i<len;i++){
            if(st.count(s.substr(index,i+1-index)) && solve(i+1,dp))
                return dp[index]=true;
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s=s;
        for(auto str:wordDict)
            st.insert(str);
        len=s.size();
        vector<int> dp(len,-1);
        return solve(0,dp);
    }
};