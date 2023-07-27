#define ll long long
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> first;
        priority_queue<int,vector<int>,greater<int>> last;
        int len=costs.size();
        int inF=0,inL=len-1;
        for(int i=0;i<candidates;i++){
            if(inF<=inL)
                first.push(costs[inF++]);
            if(inF<=inL)
                last.push(costs[inL--]);
        }
        ll cost=0;
        while(k--){
            if(last.empty() || (!first.empty()) && first.top()<=last.top()){
                cost+=first.top();
                first.pop();
                if(inF<=inL)
                    first.push(costs[inF++]);
            }
            else{
                cost+=last.top();
                last.pop();
                if(inF<=inL)
                    last.push(costs[inL--]);
            }
        }
        return cost;
    }
    
    // long long totalCost(vector<int>& costs, int k, int candidates) {
    //     priority_queue<int,vector<int>,greater<int>> first;
    //     priority_queue<int,vector<int>,greater<int>> last;
    //     int len=costs.size();
    //     int inF=0,inL=len-1;
    //     for(int i=0;i<candidates;i++){
    //         if(inF<=inL)
    //             first.push(costs[inF++]);
    //         if(inF<=inL)
    //             last.push(costs[inL--]);
    //     }
    //     ll cost=0;
    //     while(k--){
    //         if(first.empty()){
    //             cost+=last.top();
    //             last.pop();
    //             if(inF<=inL)
    //                 last.push(costs[inL--]);
    //         }
    //         else if(last.empty()){
    //             cost+=first.top();
    //             first.pop();
    //             if(inF<=inL)
    //                 first.push(costs[inF++]);
    //         }
    //         else if(first.top()<=last.top()){
    //             cost+=first.top();
    //             first.pop();
    //             if(inF<=inL)
    //                 first.push(costs[inF++]);
    //         }
    //         else{
    //             cost+=last.top();
    //             last.pop();
    //             if(inF<=inL)
    //                 last.push(costs[inL--]);
    //         }
    //     }
    //     return cost;
    // }
};