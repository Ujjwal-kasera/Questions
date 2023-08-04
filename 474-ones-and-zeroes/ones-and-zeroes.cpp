class Solution {
public: 
    int one_max,zero_max,len;
    unordered_map<string,pair<int,int>> mp;
    int solveMemo(vector<string>&strs,int one,int zero,int index,vector<vector<vector<int>>> &dp){
        if(index>=len || one>one_max || zero>zero_max)
            return 0;
        
        if(dp[index][one][zero]!=-1)
            return dp[index][one][zero];

        int incl=0;
        if((one+mp[strs[index]].first<=one_max) && (zero+mp[strs[index]].second<=zero_max))
            incl=1+solveMemo(strs,one+mp[strs[index]].first,zero+mp[strs[index]].second,index+1,dp);
        int excl=solveMemo(strs,one,zero,index+1,dp);
        dp[index][one][zero]=max(incl,excl);
        return dp[index][one][zero];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        len=strs.size();
        one_max=n;
        zero_max=m;
        int one,zero,tmp;
        for(int i=0;i<len;i++){
            zero=count(strs[i].begin(),strs[i].end(),'0');
            one=strs[i].size()-zero;
            mp.insert({strs[i],{one,zero}});
        }
        vector<vector<vector<int>>> dp(len,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        return solveMemo(strs,0,0,0,dp);
    }
    // int one_max,zero_max,len;
    // unordered_map<string,pair<int,int>> mp;
    // int solveMemo(vector<string>&strs,int one,int zero,int index,vector<vector<vector<int>>> &dp){
    //     if(index>=len || one>one_max || zero>zero_max)
    //         return 0;
        
    //     if(dp[index][one][zero]!=-1)
    //         return dp[index][one][zero];

    //     int incl=0;
    //     if((one+mp[strs[index]].first<=one_max) && (zero+mp[strs[index]].second<=zero_max))
    //         incl=1+solveMemo(strs,one+mp[strs[index]].first,zero+mp[strs[index]].second,index+1,dp);
    //     int excl=solveMemo(strs,one,zero,index+1,dp);
    //     dp[index][one][zero]=max(incl,excl);
    //     return dp[index][one][zero];
    // }

    // int findMaxForm(vector<string>& strs, int m, int n) {
    //     len=strs.size();
    //     one_max=n;
    //     zero_max=m;
    //     int one,zero,tmp;
    //     for(int i=0;i<len;i++){
    //         zero=count(strs[i].begin(),strs[i].end(),'0');
    //         one=strs[i].size()-zero;
    //         mp.insert({strs[i],{one,zero}});
    //     }
    //     vector<vector<vector<int>>> dp(len,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
    //     return solveMemo(strs,0,0,0,dp);
    // }
};