class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> person(n,0);
        int len=trust.size();
        for(int i=0;i<len;i++){
            person[trust[i][0]-1]--;
            person[trust[i][1]-1]++;
        }
        for(int i=0;i<n;i++)
            if(person[i]==n-1)
                return i+1;
        return -1;
    }
};