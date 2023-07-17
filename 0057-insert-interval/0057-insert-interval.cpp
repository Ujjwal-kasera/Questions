class Solution {
public:
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len=intervals.size();
        int index=0;
        vector<vector<int>> res;
        int start=newInterval[0],end=newInterval[1];
        while(index<len && intervals[index][1]<start)
            res.push_back(intervals[index++]);
        
        while(index<len && intervals[index][0]<=end){
            start=min(start,intervals[index][0]);
            end=max(end,intervals[index++][1]);
        }
        res.push_back({start,end});
        
        while(index<len)
            res.push_back(intervals[index++]);
        
        return res;
    }
};