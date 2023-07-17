class Solution {
public:
    // Approach 1
    // Insert the given new interval in the interval array..sort the array
    // And Now merge the array 
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     int len=intervals.size();
    //     intervals.push_back(newInterval);
    //     vector<vector<int>> res;
    //     sort(intervals.begin(),intervals.end());
    //     int start=intervals[0][0],end=intervals[0][1];
    //     for(int i=1;i<=len;++i){
    //         if(intervals[i][0]<=end){
    //             end=max(end,intervals[i][1]);
    //             continue;
    //         }
    //         else{
    //             res.push_back({start,end});
    //             start=intervals[i][0];
    //             end=intervals[i][1];
    //         }
    //     }
    //     res.push_back({start,end});
    //     return res;
    // }
    
    // Apporach 2
    // pichle approach me hm jo array me insert ke ke phr se sort kr rhe the use hm optimise krege
    // kyu ki hmra jo interval newinterval se intersect kr rha whi us change hoga baki nhi hoga 
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