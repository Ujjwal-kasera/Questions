#define ll long long
class Solution {
public:
    int req,ppl;
    map<string,int> skillId;
    vector<int> pSkill;
    map<string,ll> dp;
    
//     void solve(int index,vector<int> &ans,int sMask){
//         if(index==ppl){
//             if(sMask==(1<<req)-1){
//                 if(res.size()==0 || ans.size()<res.size()){
//                     res=ans;
//                 }
//             }
//             return;
//         }
        
//         // Take
//         ans.push_back(index);
//         solve(index+1,ans,sMask|pSkill[index]);
//         ans.pop_back();
        
//         // Not to Take
//         solve(index+1,ans,sMask);
//     }
    
    ll solve(int index,int sMask){
        if(sMask==(1<<req)-1)
            return 0;
        if(index==ppl)
            return INT_MAX;
        
        string key=to_string(index)+" "+to_string(sMask);
        if(dp.count(key))
            return dp[key];
        
        ll ans;
        // Take
        ll take=solve(index+1,sMask|pSkill[index]);
        
        // Not to Take
        ll notTaken=solve(index+1,sMask);
        
        if (__builtin_popcountll(take) < __builtin_popcountll(notTaken))
            ans=take | 1LL<<index;
        else
            ans= notTaken;
        dp[key]=ans;
        return ans;
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        req=req_skills.size();
        ppl=people.size();
        
        for(int i=0;i<req;++i)
            skillId[req_skills[i]]=i;
        
        int sSize,val;
        pSkill.assign(ppl,0);
        for(int i=0;i<ppl;++i){
            sSize=people[i].size();
            val=0;
            for(int j=0;j<sSize;++j){
                val |= 1<<skillId[people[i][j]];
            }
            pSkill[i]=val;
        }
        ll ans=solve(0,0);
        int index=0;
        vector<int> res;
        while(ans){
            if(ans&1)
                res.push_back(index);
            ++index;
            ans>>=1;
        }
        return res;
    }
};