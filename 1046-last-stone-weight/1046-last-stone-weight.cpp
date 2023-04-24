class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> h;
        for(int i:stones)
            h.push(i);
        int x,y;
        while(h.size()>1){
            y=h.top();
            h.pop();
            x=h.top();
            h.pop();
            if(y!=x)
                h.push(y-x);
        }
        return h.size()==0?0:h.top();
    }
};