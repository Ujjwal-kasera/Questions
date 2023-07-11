class compare{
public:
    // If we Don't call it by reference then it will allocate the memory
    // every time,although it will pass all the test cases but
    // TLE will occur so it will be not submitted 
    bool operator()(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
}cmp;
class Solution {
public:
    // Can also define comparator in this way
    // static bool cmp(vector<int> &a,vector<int> &b){
    //         return a[1]<b[1];
    // }
    int findMinArrowShots(vector<vector<int>>& points) {
        int res=1;
        int len=points.size();
        sort(points.begin(),points.end(),cmp);
        int mini=points[0][1];
        for(int i=1;i<len;++i){
            if(points[i][0]<=mini)
                continue;
            else{
                res++;
                mini=points[i][1];
            }
        }
        return res;
    }
};