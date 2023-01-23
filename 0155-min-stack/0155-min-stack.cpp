class MinStack {
    private:
    vector<pair<int,int>> Stack;
public:
    MinStack() {}
    
    void push(int val) {
        if(Stack.empty()){
            Stack.push_back({val,val});
            return;
        }
        int prev=min(val,Stack.back().second);
        Stack.push_back({val,prev});
    }
    
    void pop() {
        Stack.pop_back();
    }
    
    int top() {
        return Stack.back().first;
    }
    
    int getMin() {
        return Stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */