#define ll long long
class Solution {
public:
    // long long putMarbles(vector<int>& weights, int k) {
    //     int len=weights.size();
    //     int tmp;
    //     vector<int> vec(len-1);
    //     for(int i=0;i<len-1;i++){
    //         vec[i]=weights[i]+weights[i+1];
    //     }
    //     sort(vec.begin(),vec.end());
    //     ll ans=0;
    //     for(int i=0;i<k-1;i++){
    //         ans+=vec[len-i-2]-vec[i];
    //     }
    //     return ans;
    // }
    
    // To avoid sorting which cost O(nlogn),we will be using heap
    long long putMarbles(vector<int>& weights, int k) {
        int len=weights.size();
        int tmp;
        priority_queue<int> max_heap;
        priority_queue<int,vector<int>,greater<int>> min_heap;
        for(int i=0;i<len-1;i++){
            tmp=weights[i]+weights[i+1];
            min_heap.push(tmp);
            max_heap.push(tmp);
            if(min_heap.size()>k-1){
                min_heap.pop();
                max_heap.pop();
            }
        }
        ll ans1=0,ans2=0;
        for(int i=0;i<k-1;i++){
            ans1+=max_heap.top();
            ans2+=min_heap.top();
            max_heap.pop();
            min_heap.pop();
        }
        return ans2-ans1;
    }
};