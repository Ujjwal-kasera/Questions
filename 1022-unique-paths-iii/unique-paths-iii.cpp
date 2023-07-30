class Solution {
public:
    int empty=0;
    int srcX,srcY;
    int destiX,destiY;
    int lenX,lenY;
    void traverse(vector<vector<int>>&grid){
        for(int x=0;x<lenX;x++){
            for(int y=0;y<lenY;y++){
                if(grid[x][y]==2){
                    destiX=x;
                    destiY=y;
                }
                if(grid[x][y]==1){
                    srcX=x;
                    srcY=y;
                }
                if(grid[x][y]==0)
                    empty++;
            }
        }
    }
    int solveRec(vector<vector<int>>&grid,int x,int y,int emp){
        if(x<0 || x==lenX || y<0 || y==lenY)
            return 0;
        if(grid[x][y]==3 || grid[x][y]==-1)
            return 0;
        if(x==destiX && y==destiY && emp==-1)
            return 1;
        if(emp<0)
            return 0;
        grid[x][y]=3;
        int ans=0;
        // Down
        ans+=solveRec(grid,x+1,y,emp-1);
        // Upward
        ans+=solveRec(grid,x,y-1,emp-1);
        // Left
        ans+=solveRec(grid,x-1,y,emp-1);
        // Right
        ans+=solveRec(grid,x,y+1,emp-1);
        grid[x][y]=0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        lenX=grid.size();
        lenY=grid[0].size();
        traverse(grid);
        return solveRec(grid,srcX,srcY,empty);
    }
};