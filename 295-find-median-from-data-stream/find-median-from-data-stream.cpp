class MedianFinder {
    double median=0;
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(num<=median)
            left.push(num);
        else
            right.push(num);
    }
    
    double findMedian() {
        while(left.size()<right.size()){
            left.push(right.top());
            right.pop();
        }
        while(left.size()-right.size()>1){
            right.push(left.top());
            left.pop();
        }
        if(left.size()==right.size()){
            return (left.top()+right.top())/2.0;
        }
        return median=left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */