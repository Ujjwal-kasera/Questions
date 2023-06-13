class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int len=grid.size();
        bool flag=0;
        int ans=0;
        for(int row=0;row<len;row++){
            for(int col=0;col<len;col++){
                flag=1;
                for(int idx=0;idx<len;idx++){
                    if(grid[row][idx]!=grid[idx][col]){
                        flag=0;
                        break;
                    }
                }
                if(flag)
                    ans++;
            }
        }
        return ans;
    }
};