class KthLargest {
    int size;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto ele:nums)
            minHeap.push(ele);
        while(minHeap.size()>size)
            minHeap.pop();
    }
    
    int add(int val) {
        minHeap.push(val);
        while(minHeap.size()>size)
            minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */