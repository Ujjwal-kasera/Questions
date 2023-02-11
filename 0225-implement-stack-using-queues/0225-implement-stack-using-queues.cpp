class MyStack {
    queue<int> q;
    int qtop;
public:
    MyStack() {
        qtop=-1;
    }
    
    void push(int x) {
        qtop=x;
        q.push(x);
    }
    
    int pop() {
        int newTop=-1;
        int ans;
        int len=q.size()-1;
        while(len--){
            newTop=q.front();
            q.push(newTop);
            q.pop();
        }
        ans=q.front();
        qtop=newTop;
        q.pop();
        return ans;
    }
    
    int top() {
        return qtop;
    }
    
    bool empty() {
        if(q.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */