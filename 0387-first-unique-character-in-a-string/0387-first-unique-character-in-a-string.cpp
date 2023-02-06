class Solution {
public:
    // int firstUniqChar(string s) {
    //     vector<int> res(26,0);
    //     int len=s.size();
    //     for(int i=0;i<len;i++)
    //         res[s[i]-'a']++;
    //     for(int i=0;i<len;i++)
    //         if(res[s[i]-'a']==1)
    //             return i;
    //     return -1;
    // }
    int firstUniqChar(string s) {
        int len=s.size();
        unordered_map<char,int>count;
        queue<int> q;
        int ans;
        for(int i=0;i<len;i++){
            count[s[i]]++;
            q.push(i);
            while(!q.empty()){
                if(count[s[q.front()]]>1)
                    q.pop();
                else{
                    ans=q.front();
                    break;
                }
            }
        }
        if(q.empty())
                return -1;
        return ans;   
    }
};