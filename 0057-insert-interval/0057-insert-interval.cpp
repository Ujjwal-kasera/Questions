class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len=intervals.size();
        intervals.push_back(newInterval);
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<=len;++i){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
                continue;
            }
            else{
                res.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        res.push_back({start,end});
        return res;
    }
};