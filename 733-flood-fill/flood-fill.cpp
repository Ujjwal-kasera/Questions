class Solution {
public:
    int rowLen,colLen,Col,newCol;
    void paint(vector<vector<int>>&image,int sr,int sc){
        if(sr<0 || sr>=rowLen || sc<0 || sc>=colLen || image[sr][sc]!=Col)
            return;
        image[sr][sc]=newCol;
        // Down
        paint(image,sr+1,sc);
        // Up
        paint(image,sr-1,sc);
        // Left
        paint(image,sr,sc-1);
        // Right
        paint(image,sr,sc+1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        newCol=color;
        Col=image[sr][sc];
        rowLen=image.size();
        colLen=image[0].size();
        if(Col!=newCol)
            paint(image,sr,sc);
        return image;
    }
};